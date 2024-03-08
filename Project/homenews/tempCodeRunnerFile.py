from PIL import Image, ImageDraw
from io import BytesIO
import requests
import time
import os
from bs4 import BeautifulSoup

def extract_article_data(article_div):
    # Extract and return relevant data from the article div
    image_url = article_div.find('img')['src']
    article_details = article_div.find_next_sibling('div', class_='img-context')
    article_title_full = article_details.find('h2', class_='title').find('a')['title']
    article_title = article_title_full
    article_link = article_details.find('h2', class_='title').find('a')['href']
    article_date = article_details.find('div', class_='date').text.strip()
    article_content_full = article_details.find('p').text.strip()

    if len(article_content_full) < 124:
        # If content is less than 124 characters, add an extra empty line
        article_content = article_content_full + '\n'
    else:
        article_content = article_content_full

    return image_url, article_title, article_date, article_link, article_content

def download_image(image_url, filename, target_size=(361, 225), corner_radius=10):
    # Make a GET request for the image
    response = requests.get(image_url)

    # Open the image using PIL
    image = Image.open(BytesIO(response.content))

    # Resize the image to the target size
    resized_image = image.resize(target_size, Image.NEAREST)  # Use NEAREST filter for BMP

    # Create a mask with rounded corners
    mask = Image.new("L", resized_image.size, 0)
    draw = ImageDraw.Draw(mask)
    draw.rectangle((0, 0, resized_image.width, resized_image.height), fill=255)
    draw.ellipse((0, 0, corner_radius * 2, corner_radius * 2), fill=0)
    draw.ellipse((0, resized_image.height - corner_radius * 2, corner_radius * 2, resized_image.height), fill=0)
    draw.ellipse((resized_image.width - corner_radius * 2, 0, resized_image.width, corner_radius * 2), fill=0)
    draw.ellipse((resized_image.width - corner_radius * 2, resized_image.height - corner_radius * 2, resized_image.width, resized_image.height), fill=0)

    # Apply the mask to the image
    resized_image.putalpha(mask)

    # Save the resized image to the "homenews" folder
    image_folder = "homenews"
    os.makedirs(image_folder, exist_ok=True)
    image_path = os.path.join(image_folder, filename)
    resized_image.save(image_path, "BMP")

def delete_images():
    # Delete all image files in the "homenews" folder
    image_folder = "homenews"
    for file in os.listdir(image_folder):
        if file.endswith(".bmp"):
            os.remove(os.path.join(image_folder, file))

def extract_article_content(article_link):
    # Fetch the HTML content of the article link
    response = requests.get(article_link)
    html_content = response.content

    # Parse the HTML using BeautifulSoup
    soup = BeautifulSoup(html_content, 'html.parser')

    # Find and extract the text content from all <p> tags
    paragraphs = soup.find_all('p')
    article_content = '\n'.join([p.text.strip() for p in paragraphs])

    return article_content

url = "https://indianexpress.com/section/sports/cricket/"
articles_per_iteration = 1  # Set to 1 to process one article at a time
total_iterations = 10

text_folder = "homenews"
os.makedirs(text_folder, exist_ok=True)
text_file_path = os.path.join(text_folder, 'sports_articles.txt')

while True:
    try:
        for iteration in range(1, total_iterations + 1):
            response = requests.get(url)
            html_content = response.content

            soup = BeautifulSoup(html_content, 'html.parser')
            all_articles_divs = soup.find_all('div', class_='articles')

            delete_images()

            articles_div = all_articles_divs[(iteration - 1) % len(all_articles_divs)]
            for i, article_div in enumerate(articles_div.find_all('div', class_='snaps')):
                image_url, article_title, article_date, article_link, _ = extract_article_data(article_div)

                download_image(image_url, f"{i+1}_image.bmp")

                with open(text_file_path, 'w', encoding='utf-8') as file:
                    article_title_lines = [article_title[i:i+65] for i in range(0, len(article_title), 65)]
                    formatted_article_title = '\n'.join(article_title_lines)
                    file.write(f"{formatted_article_title}\n")

                    file.write(f"{article_date}\n")

                    article_content = extract_article_content(article_link)
                    article_content_lines = [article_content[i:i+60] for i in range(0, len(article_content), 60)]
                    formatted_article_content = '\n'.join(article_content_lines)
                    file.write(f"{formatted_article_content}\n")

            print(f"Data and images for iteration {iteration} have been written to {text_file_path}")

            time.sleep(6)

    except Exception as e:
        print(f"An error occurred: {e}")

import os
import requests
from bs4 import BeautifulSoup
from PIL import Image
from io import BytesIO

def extract_article_data(article_div):
    # Extract and return truncated title and content from the article div
    article_details = article_div.find_next_sibling('div', class_='img-context')
    article_title_full = article_details.find('h2', class_='title').find('a')['title']
    article_link = article_details.find('h2', class_='title').find('a')['href']
    article_date = article_details.find('div', class_='date').text.strip()
    article_content_full = article_details.find('p').text.strip()

    # Truncate title and content to the first 54 characters and break into new lines
    truncated_title = "\n".join(article_title_full[i:i+54] for i in range(0, len(article_title_full), 54))
    truncated_content = "\n".join(article_content_full[i:i+54] for i in range(0, len(article_content_full), 54))

    # Concatenate truncated title and content
    truncated_article = "{}\n{}\n{}".format(truncated_title, article_date, truncated_content)

    return article_link, truncated_article

def download_image(image_url, filename, target_size=(324, 190)):
    # Check if the image file in the 'detailnews' folder already exists
    if os.path.exists(os.path.join('detailnews', filename)):
        os.remove(os.path.join('detailnews', filename))  # Delete the existing image file

    # Make a GET request for the image
    response = requests.get(image_url)

    # Open the image using PIL
    image = Image.open(BytesIO(response.content))

    # Resize the image to the target size
    resized_image = image.resize(target_size, Image.NEAREST)  # Use NEAREST filter for BMP

    # Save the resized image to a BMP file in the 'detailnews' folder
    os.makedirs('detailnews', exist_ok=True)
    resized_image.save(os.path.join('detailnews', filename), "BMP")

def extract_text_from_article_page(article_link):
    # Make a GET request for the article page
    response = requests.get(article_link)
    article_html_content = response.content

    # Parse the HTML using BeautifulSoup
    article_soup = BeautifulSoup(article_html_content, 'html.parser')

    # Extract content within the <p> tags
    article_content_paragraphs = article_soup.find_all('p')

    # Extracted text from <p> tags
    extracted_text = "\n".join(paragraph.text.strip() for paragraph in article_content_paragraphs)

    # Break the text into a new line after every 100 characters
    extracted_text = '\n'.join(extracted_text[i:i+150] for i in range(0, len(extracted_text), 150))

    return extracted_text

url = "https://indianexpress.com/section/sports/cricket/"
articles_to_extract = 15

# Delete existing BMP images in the 'detailnews' folder
for file in os.listdir('detailnews'):
    if file.endswith(".bmp"):
        os.remove(os.path.join('detailnews', file))

# Fetch the HTML content
response = requests.get(url)
html_content = response.content

# Parse the HTML using BeautifulSoup
soup = BeautifulSoup(html_content, 'html.parser')

# Find all divs with class 'articles'
all_articles_divs = soup.find_all('div', class_='articles')

# Counter to limit the number of articles
article_count = 0

# Open a text file for writing in the 'detailnews' folder
output_file_path = os.path.join('detailnews', 'sports_articles.txt')
with open(output_file_path, 'w', encoding='utf-8') as file:
    # Iterate through each 'articles' div up to the specified limit
    for articles_div in all_articles_divs[:articles_to_extract]:
        # Extract data from each article within the 'articles' div
        for article_div in articles_div.find_all('div', class_='snaps'):
            article_link, truncated_article_data = extract_article_data(article_div)

            # Write the truncated article data to the file
            file.write(truncated_article_data)
            file.write('\n\n')  # Add an extra empty line between articles

            # Download the image in BMP format and resize it
            download_image(article_div.find('img')['src'], f"{article_count + 1}_image.bmp")

            # Extract text from the article page and write to the file
            extracted_text = extract_text_from_article_page(article_link)
            file.write(f"Additional Text from Article Page:\n{extracted_text}\n\n")

            # Increment the article count
            article_count += 1

            # Break the loop if the desired number of articles have been extracted
            if article_count >= articles_to_extract:
                break

print(f"Data and images for {articles_to_extract} articles have been saved to {output_file_path}")

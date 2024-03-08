import requests
from bs4 import BeautifulSoup
import time
import os
from PIL import Image
from io import BytesIO

def extract_article_data(article_div):
    image_url = article_div.find('img')['src']
    article_details = article_div.find_next_sibling('div', class_='img-context')
    article_title_full = article_details.find('h2', class_='title').find('a')['title']
    article_title = article_title_full[:70]
    article_link = article_details.find('h2', class_='title').find('a')['href']
    article_date = article_details.find('div', class_='date').text.strip()
    article_content_full = article_details.find('p').text.strip()

    if len(article_content_full) < 124:
        article_content = article_content_full + '\n'
    else:
        article_content_lines = [article_content_full[i:i+115] for i in range(0, len(article_content_full), 124)][:2]
        article_content = '\n'.join(article_content_lines)

    return image_url, "{}...\n{}\n{}".format(article_title, article_date, article_content)

def download_image(image_url, filename, target_size=(216, 128)):
    response = requests.get(image_url)
    image = Image.open(BytesIO(response.content))
    resized_image = image.resize(target_size, Image.NEAREST)
    resized_image.save(filename, "BMP")

def delete_images():
    for file in os.listdir():
        if file.endswith(".bmp"):
            os.remove(file)

url = "https://indianexpress.com/section/sports/cricket/"
articles_per_iteration = 3
iterations = 5

for iteration in range(iterations):
    response = requests.get(url)
    html_content = response.content
    soup = BeautifulSoup(html_content, 'html.parser')
    all_articles_divs = soup.find_all('div', class_='articles')
    delete_images()

    with open('sports_articles.txt', 'w', encoding='utf-8') as file:
        for i, articles_div in enumerate(all_articles_divs[iteration * articles_per_iteration : (iteration + 1) * articles_per_iteration]):
            for article_div in articles_div.find_all('div', class_='snaps'):
                image_url, _ = extract_article_data(article_div)
                download_image(image_url, f"{i+1}_image.bmp")

        for i, articles_div in enumerate(all_articles_divs[iteration * articles_per_iteration : (iteration + 1) * articles_per_iteration]):
            for article_div in articles_div.find_all('div', class_='snaps'):
                _, article_data = extract_article_data(article_div)
                file.write(article_data)
                file.write('\n')

    print(f"Data and images for iteration {iteration + 1} have been saved to sports_articles.txt")
    time.sleep(6)

import requests
from bs4 import BeautifulSoup
import time
import os

def extract_article_data(article_div):
    # Extract and return relevant data from the article div
    article_details = article_div.find_next_sibling('div', class_='img-context')
    article_title_full = article_details.find('h2', class_='title').find('a')['title']

    return article_title_full

def delete_images():
    # Delete all image files in the current working directory
    for file in os.listdir():
        if file.endswith(".bmp"):
            os.remove(file)

url = "https://indianexpress.com/section/sports/cricket/"
articles_per_iteration = 5

# Set the number of iterations or a condition to break out of the loop
iterations = 5

# Open a text file for writing article titles
file_path = 'article_titles.txt'
for iteration in range(iterations):
    # Fetch the HTML content
    response = requests.get(url)
    if response.status_code != 200:
        print(f"Error: Unable to fetch content. Status Code: {response.status_code}")
        continue  # Skip to the next iteration

    html_content = response.content

    # Parse the HTML using BeautifulSoup
    soup = BeautifulSoup(html_content, 'html.parser')

    # Find all divs with class 'articles'
    all_articles_divs = soup.find_all('div', class_='articles')

    # Delete existing images
    delete_images()

    # Write the article_title_full for each article to the text file with line breaks
    with open(file_path, 'w', encoding='utf-8') as title_file:
        for i, articles_div in enumerate(all_articles_divs[iteration * articles_per_iteration : (iteration + 1) * articles_per_iteration]):
            for article_div in articles_div.find_all('div', class_='snaps'):
                article_title_full = extract_article_data(article_div)

                # Break lines after every 20 characters and write to the file
                for j in range(0, len(article_title_full), 29):
                    title_file.write(article_title_full[j:j+29] + '\n')

    print(f"Article titles for iteration {iteration + 1} have been written to {file_path}.")

    # Wait for 6 seconds before repeating the process
    time.sleep(6)

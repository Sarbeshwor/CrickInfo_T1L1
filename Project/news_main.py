import requests
from bs4 import BeautifulSoup
import time

def extract_article_title(article_div):
    # Extract and return the full title from the article div
    article_details = article_div.find_next_sibling('div', class_='img-context')
    article_title_full = article_details.find('h2', class_='title').find('a')['title']
    return article_title_full.strip()

url = "https://indianexpress.com/section/sports/cricket/"
file_name = 'mostread.txt'
headlines_count = 5

while headlines_count > 0:
    # Fetch the HTML content
    response = requests.get(url)
    html_content = response.content

    # Parse the HTML using BeautifulSoup
    soup = BeautifulSoup(html_content, 'html.parser')

    # Find all divs with class 'snaps'
    all_articles_divs = soup.find_all('div', class_='snaps')

    # Open the text file for writing
    with open(file_name, 'w', encoding='utf-8') as file:
        # Extract and write full titles from the first 5 divs with an extra empty line between titles
        for i, article_div in enumerate(all_articles_divs[:headlines_count]):
            file.write(extract_article_title(article_div))
            if i < headlines_count - 1:
                file.write('\n')  # Add an extra empty line if it's not the last article

    print("Full titles have been saved to", file_name)

    # Wait for 6 seconds before repeating the process
    time.sleep(6)

    headlines_count -= 1

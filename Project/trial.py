import requests
from bs4 import BeautifulSoup
import time

def extract_article_data(article_div):
    # Extract and return full title and content from the article div
    article_details = article_div.find_next_sibling('div', class_='img-context')
    article_title_full = article_details.find('h2', class_='title').find('a')['title']
    article_link = article_details.find('h2', class_='title').find('a')['href']
    article_date = article_details.find('div', class_='date').text.strip()
    article_content_full = article_details.find('p').text.strip()

    # Concatenate full title and content
    full_article = "{}\n{}\n{}".format(article_title_full, article_date, article_content_full)
    
    return full_article

url = "https://indianexpress.com/section/sports/cricket/"
articles_per_iteration = 3

# Set the number of iterations or a condition to break out of the loop
while True:
    # Fetch the HTML content
    response = requests.get(url)
    html_content = response.content

    # Parse the HTML using BeautifulSoup
    soup = BeautifulSoup(html_content, 'html.parser')

    # Find all divs with class 'articles'
    all_articles_divs = soup.find_all('div', class_='articles')

    # Open a text file for writing
    with open('detai_article.txt', 'w', encoding='utf-8') as file:
        # Extract data from the next set of 3 divs with an extra empty line between news articles
        for articles_div in all_articles_divs[:articles_per_iteration]:
            for article_div in articles_div.find_all('div', class_='snaps'):
                full_article_data = extract_article_data(article_div)

                # Write the full article data to the file
                file.write(full_article_data)
                file.write('\n\n')  # Add an extra empty line between articles

    print("Data has been saved to sports_articles.txt")

    # Wait for 6 seconds before repeating the process
    time.sleep(6)

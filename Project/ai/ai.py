import requests
from bs4 import BeautifulSoup
from urllib.parse import urlparse

# Read the query from the file
with open('query.txt', 'r') as file:
    query_text = file.read().strip()

# Construct the URL with the query
url = f'https://iask.ai/?mode=question&options[detail_level]=concise&q={query_text.replace(" ", "+")}'

# Extract the website from the search URL
parsed_url = urlparse(url)
website = parsed_url.netloc

# Perform the search
response = requests.get(url)

# Check if the request was successful (status code 200)
if response.status_code == 200:
    print(f"Search URL: {url}")
    print(f"Website: {website}")

    # Parse the HTML content
    soup = BeautifulSoup(response.text, 'html.parser')

    # Find all paragraphs within the HTML
    paragraphs = soup.find_all('p')

    if paragraphs:
        # Extract text from all paragraphs
        extracted_text = '\n'.join(tag.get_text(strip=True, separator='\n') for tag in paragraphs)

        # Save the extracted text in a new txt file (answer.txt)
        with open('answer.txt', 'w',encoding='utf-8') as answer_file:
            answer_file.write(extracted_text)

        print("Search successful. Extracted text saved in answer.txt.")
        print("Extracted text:")
        print(extracted_text)
    else:
        print("No paragraphs found. Check the HTML structure.")
else:
    print(f"Search failed. Status code: {response.status_code}")

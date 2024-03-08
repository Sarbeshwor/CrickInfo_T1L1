import requests
from bs4 import BeautifulSoup

url = "https://www.google.com/search?q=cricke+live+score&oq=cricke+live+score&gs_lcrp=EgZjaHJvbWUyBggAEEUYOTIJCAEQABgKGIAEMgkIAhAAGAoYgAQyCQgDEAAYChiABDIJCAQQABgKGIAEMgYIBRBFGD0yBggGEEUYPDIGCAcQRRg80gEIODAzN2owajeoAgCwAgA&sourceid=chrome&ie=UTF-8"

# Send an HTTP request
response = requests.get(url)

# Parse the HTML content
soup = BeautifulSoup(response.text, 'html.parser')

# Find the table with class 'KAIX8d'
table = soup.find('table', class_='KAIX8d')

# Check if the table exists before proceeding
if table:
    # Find the span within the table with class 'imspo_mt__lg-st-co'
    span = table.find('span', class_='imspo_mt__lg-st-co')

    # Extract the text from the span
    result = span.text if span else "Span not found."

    # Print the result
    print(result)
else:
    print("Table with class 'KAIX8d' not found.")

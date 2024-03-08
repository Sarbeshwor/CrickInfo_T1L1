import os
import requests
from bs4 import BeautifulSoup
from urllib.parse import urljoin
from PIL import Image
from io import BytesIO

url = "https://www.cricbuzz.com/"
response = requests.get(url)

if response.status_code == 200:
    soup = BeautifulSoup(response.text, 'html.parser')

    team_image_elements = soup.find_all('div', class_='cb-hmscg-tm-nm-img')

    os.makedirs('livescore', exist_ok=True)

    existing_files = [f for f in os.listdir('livescore') if f.endswith('.bmp')]
    for file in existing_files:
        os.remove(os.path.join('livescore', file))

    for i, team_image_element in enumerate(team_image_elements, start=1):
        img_element = team_image_element.find('img')

        if img_element:
            team_image_url = urljoin(url, img_element['src'])

            team_image_response = requests.get(team_image_url)
            if team_image_response.status_code == 200:
                img = Image.open(BytesIO(team_image_response.content))

                img.save(os.path.join('livescore', f"{i}_{i}.bmp"))
                print(f"Team image {i} downloaded and saved as .bmp successfully.")
            else:
                print(f"Failed to download team image {i}. Status code: {team_image_response.status_code}")
        else:
            print(f"No img element found for team {i}.")

else:
    print(f"Failed to fetch the webpage. Status code: {response.status_code}")

import requests
from bs4 import BeautifulSoup
import time

def fetch_and_update_data():
    url = "https://www.cricbuzz.com/cricket-stats/icc-rankings/men/teams"
    response = requests.get(url)

    if response.status_code == 200:
        soup = BeautifulSoup(response.text, 'html.parser')

        data_file = open('./team_rankings.txt', 'w', encoding='utf-8')

        team_divs = soup.find_all('div', class_='cb-col cb-col-100 cb-font-14 cb-brdr-thin-btm text-center')
        team_name_width = 29

        for div in team_divs[1:11]:  # Starting from 1 to skip the header
            team_name_element = div.find_next('div', class_='cb-col-50')
            rating_element = div.find_next('div', class_='cb-col-14')

            team_name = team_name_element.get_text(strip=True) if team_name_element else "N/A"
            rating = rating_element.get_text(strip=True) if rating_element else "N/A"

            data_file.write(f"{team_name.ljust(team_name_width)}{rating}\n")

        data_file.close()
        print("Data extraction successful. Check 'team_rankings.txt'")
    else:
        print(f"Error accessing the webpage. Status code: {response.status_code}")

while True:
    fetch_and_update_data()
    time.sleep(6)  # Sleep for 10 minutes (600 seconds)

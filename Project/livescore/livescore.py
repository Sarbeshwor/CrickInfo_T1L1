import requests
from bs4 import BeautifulSoup
import time

url = "https://www.cricbuzz.com/"

def extract_match_details(match):
    match_title = match.find('a')['title']
    match_format = match.find('div', class_='cb-card-match-format').text.strip()

    team_elements = match.find_all('span', class_='text-normal')
    score_elements = match.find_all('div', class_='cb-ovr-flo')
    if len(team_elements) == 2 and len(score_elements) == 2:
        team1_name = team_elements[0].text.strip() if team_elements[0].text.strip() else team_elements[0].get('title', 'N/A')
        team1_score = score_elements[0].text.strip()
        team2_name = team_elements[1].text.strip() if team_elements[1].text.strip() else team_elements[1].get('title', 'N/A')
        team2_score = score_elements[1].text.strip()
    else:
        team1_name, team1_score, team2_name, team2_score = match_title[:4], "...", match_title, "... "

    match_state_element = match.find('div', class_='cb-mtch-crd-state')
    match_state = match_state_element.text.strip()[:42] if match_state_element else "Match Result coming..."

    return f"{match_title[:25]}\t  -{match_format[:14]}\n{team1_name.ljust(15)}{team1_score}\n{team2_name.ljust(15)}{team2_score}\n{match_state}..\n"

while True:
    response = requests.get(url)

    if response.status_code == 200:
        soup = BeautifulSoup(response.text, 'html.parser')
        match_items = soup.find_all('li', class_='cb-view-all-ga cb-match-card cb-bg-white')[:6]

        for idx, match in enumerate(match_items, start=1):
            match_details = extract_match_details(match)
            file_name = f"livescore/match_details_{idx}.txt"

            with open(file_name, 'w', encoding='utf-8') as file:
                file.write(match_details)

            print(f"Match details updated in {file_name}")

    else:
        print(f"Failed to fetch the webpage. Status code: {response.status_code}")

    time.sleep(3)  # Sleep for 3 seconds before updating again

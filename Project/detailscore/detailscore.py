import os
import requests
from bs4 import BeautifulSoup
import time

url = "https://www.cricbuzz.com/"

def extract_match_details(match):
    match_title = match.find('a')['title']
    match_link = match.find('a')['href']
    match_format = match.find('div', class_='cb-card-match-format').text.strip()

    team_elements = match.find_all('span', class_='text-normal')
    score_elements = match.find_all('div', class_='cb-col-50 cb-ovr-flo')

    if len(team_elements) == 2 and len(score_elements) == 2:
        team1_name = team_elements[0].text.strip() if team_elements[0].text.strip() else team_elements[0].get('title', 'N/A')
        team1_score = score_elements[0].text.strip()
        team2_name = team_elements[1].text.strip() if team_elements[1].text.strip() else team_elements[1].get('title', 'N/A')
        team2_score = score_elements[1].text.strip()
    else:
        team1_name, team1_score, team2_name, team2_score = match_title[:4], "...", match_title[17:24], "... "

    match_state_element = match.find('div', class_='cb-mtch-crd-state')
    match_state = match_state_element.text.strip()[:42] if match_state_element else "Match Result coming..."

    return f"{match_title[:25]}\t  -{match_format[:14]}\n{team1_name.ljust(15)}{team1_score}\n{team2_name.ljust(15)}{team2_score}\n{match_state}..\n{url}{match_link}\n"

def extract_detailed_match_info(match_link):
    detailed_response = requests.get(match_link if match_link.startswith('http') else url + match_link.replace('scores', 'scorecard'))

    if detailed_response.status_code == 200:
        detailed_soup = BeautifulSoup(detailed_response.text, 'html.parser')
        innings_info = detailed_soup.find_all('div', class_='cb-col cb-col-100 cb-ltst-wgt-hdr')[1:]

        detailed_info = ""
        for inning in innings_info:
            inning_title_element = inning.find('div', class_='cb-col cb-col-100 cb-scrd-hdr-rw')
            if inning_title_element:
                inning_title = inning_title_element.text.strip()
                detailed_info += f"\n{inning_title}\n"

                player_rows_container = inning.find_all('div', class_='cb-col cb-col-100 cb-ltst-wgt-hdr')[1]
                if player_rows_container:
                    player_rows = player_rows_container.find_all('div', class_='cb-col cb-col-100 cb-scrd-itms')

                    for row in player_rows:
                        player_name_element = row.find('a', class_='cb-col cb-col-27 cb-ltst-wgt-hdr')
                        if player_name_element:
                            player_name = player_name_element['title'].strip()
                            dismissal_info = row.find('div', class_='cb-col cb-col-8 text-right text-bold').text.strip()
                            runs = row.find_all('div', class_='cb-col cb-col-8 text-right')[0].text.strip()
                            balls = row.find_all('div', class_='cb-col cb-col-8 text-right')[1].text.strip()
                            fours = row.find_all('div', class_='cb-col cb-col-8 text-right')[2].text.strip()
                            sixes = row.find_all('div', class_='cb-col cb-col-8 text-right')[3].text.strip()
                            strike_rate = row.find_all('div', class_='cb-col cb-col-8 text-right')[4].text.strip()

                            detailed_info += f"{player_name.ljust(20)}{dismissal_info.ljust(30)}{runs.ljust(10)}{balls.ljust(10)}{fours.ljust(10)}{sixes.ljust(10)}{strike_rate}\n"

        return detailed_info

    else:
        return f"Failed to fetch detailed match info. Status code: {detailed_response.status_code}"

while True:
    response = requests.get(url)

    if response.status_code == 200:
        soup = BeautifulSoup(response.text, 'html.parser')
        match_items = soup.find_all('li', class_='cb-view-all-ga cb-match-card cb-bg-white')[:6]

        for idx, match in enumerate(match_items, start=1):
            match_details = extract_match_details(match)
            file_name = f"detailscore/match_details_{idx}.txt"

            with open(file_name, 'w', encoding='utf-8') as file:
                file.write(match_details)

            print(f"Match details updated in {file_name}")

            match_link = match.find('a')['href']
            detailed_info = extract_detailed_match_info(match_link)

            detailnews_folder = "detailscore"
            if not os.path.exists(detailnews_folder):
                os.makedirs(detailnews_folder)

            detailnews_file = os.path.join(detailnews_folder, f"detailed_info_{idx}.txt")
            with open(detailnews_file, 'w', encoding='utf-8') as details_file:
                details_file.write(detailed_info)

            print(f"Detailed match info updated in {detailnews_file}")

    else:
        print(f"Failed to fetch the webpage. Status code: {response.status_code}")

    time.sleep(3)  # Sleep for 3 seconds before updating again

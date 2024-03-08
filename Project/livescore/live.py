import requests
from bs4 import BeautifulSoup

# URL of the webpage
url = "https://www.cricbuzz.com/"

# Send a GET request to the URL
response = requests.get(url)

# Check if the request was successful (status code 200)
if response.status_code == 200:
    # Parse the HTML content using BeautifulSoup
    soup = BeautifulSoup(response.text, 'html.parser')

    # Extract team names and scores
    matches = soup.select('ul.cb-col-100.videos-carousal-wrapper.cb-mtch-crd-rt-itm > li.cb-match-card')

    extracted_data = []

    for match in matches:
        team_names = match.select('.cb-hmscg-tm-name .text-normal')
        scores = match.select('.cb-ovr-flo')

        if team_names and scores:
            team1_name = team_names[0].text
            team2_name = team_names[1].text
            team1_score = scores[0].text.strip()
            team2_score = scores[1].text.strip()

            extracted_data.append(f"{team1_name} vs {team2_name}: {team1_score} - {team2_score}")

    # Save the extracted data to a text file in the 'livescore' folder
    with open('livescore/extracted_scores.txt', 'w', encoding='utf-8') as file:
        for data in extracted_data:
            file.write(data + '\n')

    print("Extraction successful. Check 'extracted_scores.txt' in the 'livescore' folder.")
else:
    print(f"Failed to retrieve the webpage. Status code: {response.status_code}")

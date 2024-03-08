import requests
from bs4 import BeautifulSoup
from datetime import datetime

url = "https://www.cricbuzz.com/cricket-schedule/upcoming-series/domestic"
response = requests.get(url)

if response.status_code == 200:
    html = response.text
    soup = BeautifulSoup(html, 'html.parser')

    schedule_divs = soup.find_all('div', class_='cb-col-100 cb-col')

    # Open a text file for writing
    with open('domestic_schedule_info.txt', 'w', encoding='utf-8') as file:
        for schedule_div in schedule_divs:
            date_div = schedule_div.find('div', class_='cb-lv-grn-strip text-bold')
            date = date_div.text.strip() if date_div else "Date not found"

            match_info_divs = schedule_div.find_all('div', class_='cb-col-60 cb-col cb-mtchs-dy-vnu cb-adjst-lst')
            
            for match_info_div in match_info_divs:
                match_title = match_info_div.find('a', title=True)
                if match_title:
                    match_title_text = match_title['title'].strip()
                else:
                    match_title_text = "Match info not found"
                
                venue_div = match_info_div.find('div', itemprop='location')
                venue = venue_div.find('span', itemprop='name').text.strip() if venue_div else "Venue not found"

                # Extracting the date and time
                date_time_div = match_info_div.find('span', class_='schedule-date')
                timestamp = date_time_div['timestamp'] if date_time_div else None

                # Formatting date and time
                if timestamp:
                    date_time = datetime.fromtimestamp(int(timestamp) / 1000).strftime('%a, %b %d %Y %I:%M %p')
                else:
                    date_time = "Date and Time not found"

                # Calculate the number of spaces needed to make the total length 26 characters
                spaces_count = 26 - len(match_title_text) - len(date_time)

                # Create the formatted output using ljust
                formatted_output = f"{match_title_text}{' ' * spaces_count}{date_time}"

                # Write the information to the file
                file.write(f"{formatted_output} at {venue}\n")

    print("Domestic schedule information saved to domestic_schedule_info.txt")
else:
    print(f"Failed to fetch the page. Status code: {response.status_code}")

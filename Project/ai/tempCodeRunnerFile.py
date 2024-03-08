

# Check if the request was successful (status code 200)
if response.status_code == 200:
    print(f"Search URL: {url}")
    
    # Parse the HTML content
    soup = BeautifulSoup(response.text, 'html.parser')
    
    # Extract text from the first <p> tag
    first_p_tag = soup.find('p')
    answer_text = first_p_tag.text if first_p_tag else "No answer found."
    
    # Save the answer in a new txt file (answer.txt)
    with open('answer.txt', 'w') as answer_file:
        answer_file.write(answer_text)
    
    print("Search successful. Answer saved in answer.txt.")
    print("Answer:")
    print(answer_text)
else:
    print(f"Search failed. Status code: {response.status_code}")

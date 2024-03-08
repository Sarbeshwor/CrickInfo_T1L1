#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <unistd.h>
#include <curl/curl.h>
#include <htmlcxx/html/ParserDom.h>

using namespace std;

size_t WriteCallback(void* contents, size_t size, size_t nmemb, string* output) {
    size_t total_size = size * nmemb;
    output->append((char*)contents, total_size);
    return total_size;
}

string extract_article_data(htmlcxx::HTML::Node article_div) {
    // Extract and return relevant data from the article div
    auto article_details = article_div.firstChild(); // Adjusted for HTML structure
    auto article_title_full = article_details.firstChild().text();

    return article_title_full;
}

void delete_images() {
    // Delete all image files in the current working directory
    // Add platform-specific code to handle this (e.g., on Unix-like systems: system("rm *.bmp");)
}

int main() {
    string url = "https://indianexpress.com/section/sports/cricket/";
    int articles_per_iteration = 5;

    // Set the number of iterations or a condition to break out of the loop
    int iterations = 5;

    // Open a text file for writing article titles
    string file_path = "article_titles.txt";
    for (int iteration = 0; iteration < iterations; ++iteration) {
        // Fetch the HTML content
        CURL* curl;
        CURLcode res;
        curl_global_init(CURL_GLOBAL_DEFAULT);
        curl = curl_easy_init();
        string html_content;

        if (curl) {
            curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
            curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
            curl_easy_setopt(curl, CURLOPT_WRITEDATA, &html_content);

            res = curl_easy_perform(curl);

            if (res != CURLE_OK) {
                cout << "Error: Unable to fetch content. Status Code: " << res << endl;
                continue;  // Skip to the next iteration
            }

            curl_easy_cleanup(curl);
        }

        // Parse the HTML using htmlcxx
        htmlcxx::HTML::ParserDom parser;
        tree<htmlcxx::HTML::Node> dom = parser.parseTree(html_content);

        // Find all divs with class 'snaps'
        auto root = dom.begin();
        auto it = root;
        while (it != dom.end() && it.node->tagName() != "div") {
            ++it;
        }

        auto all_articles_divs = it;

        // Delete existing images
        delete_images();

        // Write the article_title_full for each article to the text file with line breaks
        ofstream title_file(file_path);
        for (auto article_div = all_articles_divs.firstChild(); article_div; article_div = article_div.nextSibling()) {
            string article_title_full = extract_article_data(article_div);

            // Break lines after every 20 characters and write to the file
            for (size_t j = 0; j < article_title_full.length(); j += 29) {
                title_file << article_title_full.substr(j, 29) << endl;
            }
        }

        cout << "Article titles for iteration " << iteration + 1 << " have been written to " << file_path << "." << endl;

        // Wait for 6 seconds before repeating the process
        sleep(6);
    }

    return 0;
}

import os
import re
import time
import requests
from urllib.parse import urljoin
from bs4 import BeautifulSoup

# Configuration
BASE_DIR = os.getcwd()  # Directory S where the script runs
COMPLETED_DIR = os.path.join(BASE_DIR, "已完成所有题目")
STATEMENTS_DIR = os.path.join(BASE_DIR, "statements")
CODEFORCES_URL = "https://codeforces.com/problemset/problem/"

# Create statements directory if it doesn't exist
os.makedirs(STATEMENTS_DIR, exist_ok=True)

# Regular expression to extract contest and problem numbers
cf_pattern = re.compile(r'CF(\d+)([A-Za-z]+)')

# Headers to mimic a browser request
HEADERS = {
    'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/91.0.4472.124 Safari/537.36',
    'Accept': 'text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,*/*;q=0.8',
    'Accept-Language': 'en-US,en;q=0.5',
    'Accept-Encoding': 'gzip, deflate, br',
    'Connection': 'keep-alive',
    'Upgrade-Insecure-Requests': '1',
    'Referer': 'https://codeforces.com/',
    'DNT': '1'
}

def extract_problem_info(filename):
    """Extract contest number and problem letter from filename"""
    match = cf_pattern.search(filename)
    if match:
        contest_num = match.group(1)
        problem_letter = match.group(2)
        return contest_num, problem_letter
    return None, None

def download_problem_statement(contest_num, problem_letter):
    """Download problem statement HTML from Codeforces"""
    problem_url = urljoin(CODEFORCES_URL, f"{contest_num}/{problem_letter}")
    
    try:
        # Add delay to avoid being blocked
        time.sleep(2)  # 2 seconds delay between requests
        
        response = requests.get(problem_url, headers=HEADERS)
        response.raise_for_status()
        
        # Check if we got a valid HTML page (not a 403 page)
        if "403 Forbidden" in response.text:
            print(f"403 Forbidden error for {contest_num}/{problem_letter}")
            return False
        
        # Parse with BeautifulSoup to get cleaner HTML
        soup = BeautifulSoup(response.text, 'html.parser')
        
        # Save to file
        filename = f"CF{contest_num}{problem_letter}.html"
        save_path = os.path.join(STATEMENTS_DIR, filename)
        
        with open(save_path, 'w', encoding='utf-8') as f:
            f.write(str(soup))
            
        print(f"Successfully downloaded: {filename}")
        return True
    
    except requests.exceptions.RequestException as e:
        print(f"Failed to download {contest_num}/{problem_letter}: {e}")
        return False

def main():
    # Walk through the completed problems directory
    for root, _, files in os.walk(COMPLETED_DIR):
        for file in files:
            if file.startswith('CF'):
                contest_num, problem_letter = extract_problem_info(file)
                if contest_num and problem_letter:
                    # Check if we already have this statement
                    expected_html = f"CF{contest_num}{problem_letter}.html"
                    html_path = os.path.join(STATEMENTS_DIR, expected_html)
                    
                    if not os.path.exists(html_path):
                        success = download_problem_statement(contest_num, problem_letter)
                        if not success:
                            print(f"Will retry {contest_num}/{problem_letter} later...")
                            # You might want to implement a retry mechanism here
                    else:
                        print(f"Already exists: {expected_html}")

if __name__ == "__main__":
    main()
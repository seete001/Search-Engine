
from time import sleep
import argparse

from bs4 import BeautifulSoup
import requests
from pathlib import Path


def extract(url):
    headers = {
        "User-Agent": "MiniSearch/1.0 Sepehr sepehr.etemadi@yahoo.com",
        "Accept-Encoding": "gzip, deflate",
        "Host": "www.sec.gov",
        "Accept": "*/*",
        "Connection": "keep-alive"
    }

    response = requests.get(
        url=url,
        headers=headers,
        timeout=30
    )

    sleep(1)

    response.raise_for_status()

    return response.text


def convert(html):
    soup = BeautifulSoup(html, "html.parser")

    for element in soup(["script", "style", "ix:header"]):
        element.decompose()

    text = soup.get_text(separator="\n")

    lines = [
        line.strip()
        for line in text.splitlines()
        if line.strip()
    ]

    return "\n".join(lines)


def save(text, filename):
    output_path = Path("data/documents")

    output_path.mkdir(parents=True, exist_ok=True)

    file_path = output_path / filename

    file_path.write_text(text, encoding="utf-8")

    print(f"Successfully saved: {file_path}")
    print(f"Characters extracted: {len(text)}")


def main():
    parser = argparse.ArgumentParser(
        description="MiniSearch SEC document extractor"
    )

    parser.add_argument("url", help="SEC filing document URL")

    parser.add_argument(
        "filename",
        help="Output filename, e.g. Apple_2024.txt"
    )

    args = parser.parse_args()

    try:
        html = extract(args.url)

        text = convert(html)

        save(text, args.filename)

    except requests.exceptions.RequestException as error:
        print(f"Download error: {error}")

    except OSError as error:
        print(f"File error: {error}")


if __name__ == "__main__":
    main()

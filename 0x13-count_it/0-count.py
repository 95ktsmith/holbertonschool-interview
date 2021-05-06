#!/usr/bin/python3
""" Count key words """
import requests


def count_words(subreddit, word_list=[], count={}, after=""):
    """
    Prints the number of times each word in word_list appears in the titles
    of posts on the front page of subreddit.
    Words with no matches are omitted.
    """

    # If default after (first function call), prep word list and count
    # dictionary
    if after == "":
        url = "https://www.reddit.com/r/{}/hot.json".format(subreddit)

        # Make list of lowercase search words
        word_list = list(map(
            lambda x: x.lower(),
            word_list
        ))

        # Build dictionary of keyword: count
        for word in word_list:
            count[word] = 0
    else:
        url = "https://www.reddit.com/r/{}/hot.json?after={}".\
              format(subreddit, after)

    r = requests.get(
        url,
        allow_redirects=False,
        headers={'User-Agent': 'PlaceholderAgent'}
    )

    # Stop if request didn't work
    if r.status_code != 200:
        return

    # Make list of lowercase titles
    posts = list(map(
        lambda x: x['data']['title'].lower(),
        r.json()['data']['children']
    ))

    # Count up for each matching word in each post title
    for title in posts:
        for word in title.split():
            for keyword in word_list:
                if word == keyword:
                    count[word] += 1

    # Print results and stop after searching last page
    if r.json()['data']['after'] is None:
        count = sorted(count.items(), key=lambda x: (-x[1], x[0]))
        for item in count:
            if item[1] != 0:
                print("{}: {}".format(item[0], item[1]))
        return

    # Count words on the next page
    count_words(subreddit, word_list, count, r.json()['data']['after'])

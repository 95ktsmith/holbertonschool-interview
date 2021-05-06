#!/usr/bin/python3
""" Count key words """
import requests


def count_words(subreddit, word_list=[], posts=[], count={}):
    """
    Prints the number of times each word in word_list appears in the titles
    of posts on the front page of subreddit.
    Words with no matches are omitted.
    """

    # If no more words to look for, print counts and return
    if len(word_list) == 0:
        count = sorted(count.items(), key=lambda x: (-x[1], x[0]))
        for item in count:
            if item[1] != 0:
                print("{}: {}".format(item[0], item[1]))
        return

    # If no posts (probably first function call), make api request
    if len(posts) == 0:
        r = requests.get(
            "https://www.reddit.com/r/{}/hot.json".format(subreddit),
            allow_redirects=False,
            headers={'User-Agent': 'PlaceholderAgent'}
        )
        if r.status_code != 200:
            return

        # Make everything lower case because case insensitive
        posts = list(map(
            lambda x: x['data']['title'].lower(),
            r.json()['data']['children']
        ))

        word_list = list(map(
            lambda x: x.lower(),
            word_list
        ))

        # Build dictionary of keyword: count
        for word in word_list:
            count[word] = 0

    # Count up for each matching word in each post title
    for title in posts:
        for word in title.split():
            if word == word_list[0]:
                count[word] += 1

    count_words(subreddit, word_list[1:], posts, count)
    return None

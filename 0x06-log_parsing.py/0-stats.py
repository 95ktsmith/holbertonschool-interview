#!/usr/bin/env python3
""" Log Parsing """
import sys


line_count = 0
file_size = 0
codes = [200, 301, 400, 401, 403, 404, 405, 500]
code_counts = {
    200: 0,
    301: 0,
    400: 0,
    401: 0,
    403: 0,
    404: 0,
    405: 0,
    500: 0
}
try:
    for line in sys.stdin:
        words = line.split()
        try:
            file_size += int(words[-1])
            code = int(words[-2])
            code_counts[code] += 1
            line_count += 1
        except Exception:
            continue
        if line_count > 0 and line_count % 10 == 0:
            print("File size: {}".format(file_size))
            for code in codes:
                if code_counts[code] > 0:
                    print("{}: {}".format(code, code_counts[code]))
except Exception:
    pass
finally:
    print("File size: {}".format(file_size))
    for code in codes:
        if code_counts[code] > 0:
            print("{}: {}".format(code, code_counts[code]))

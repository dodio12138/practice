import re
from collections import defaultdict
import requests
from bs4 import BeautifulSoup
import matplotlib.pyplot as plt
plt.rcParams["font.sans-serif"] = ["SimHei"]  # 设置字体
plt.rcParams["axes.unicode_minus"] = False  # 该语句解决图像中的“-”负号的乱码问题

check = True
time_data = []
data_count = defaultdict(int)


def loopSpider(a):
    url = 'https://www.yourlocalguardian.co.uk/memorials/?p=' + str(a)
    # print(url)

    response = requests.get(url)

    if response.status_code == 200:
        soup = BeautifulSoup(response.text, 'html.parser')

        time_elements = soup.select('.announcement-card__date')

        for element in time_elements:
            time_data.append(element.text.strip())
    else:
        check = False


def count():
    for date_string in time_data:
        date_parts = re.findall(r'\d{2}/\d{2}/\d{4}', date_string)
        if date_parts:
            formatted_date = date_parts[0]  # 取第一个匹配的日期
            # 增加对应日期的出现次数
            data_count[formatted_date] += 1


for i in range(800):
    if (check):
        loopSpider(i)
    else:
        break

count()

dates = list(range(0, time_data.count))
counts = list(data_count.values())
# print(time_data)

plt.figure(figsize=(10, 6))
# plt.bar(dates, counts)
plt.plot(dates, counts)
plt.xlabel('日期')
plt.ylabel('出现次数')
plt.title('每一天的出现次数')
plt.xticks(rotation=45)  # 使日期标签更易阅读
plt.tight_layout()

plt.show()

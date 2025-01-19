import requests
import time

cookies = {"这里要填入你的cookies"}

url = "https://eams.sufe.edu.cn/eams/stdElectCourse!batchOperator.action?profileId=10084&electLessonIds="这里要填electLessonIds"&withdrawLessonIds=&v=1736410587640&_=1736410587642"

failure_messages = ["选课失败:人数已满", "选课失败:请不要过快点击", "请重新进入选课页面"]

while True:
    try:
        req = requests.get(url, cookies=cookies)
        response_text = req.text

        print(response_text)

        if any(message in response_text for message in failure_messages):
            print("选课失败，继续尝试...")
        else:
            print("选课成功或出现其他结果，终止循环")
            break

    except Exception as e:
        print(f"请求失败: {e}")

    time.sleep(0.5)
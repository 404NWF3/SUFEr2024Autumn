# SUFER抢课教程
手慢无！相信你一定曾经有过或者未来会有抢不到心仪的课程。没关系，那就用科技改变命运。
接下来我将介绍一种用于**二轮、三轮**抢课的奇技淫巧：

#### Step1：

首先安装`python`环境，这我就不多说了，这里建议下载`pycharm`搭配`anaconda`使用；

#### Step2：
在终端运行：
```
pip install requests
```

#### Step3:
创建文件，在里边先复制以下代码`main.py`：
```python
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
```

#### Step4：
有了以上代码，想要成功抢课需要3个重要的参数，分别是`cookies`、`url`、`electLessonIds`;

> cookies
- 进入“选课系统”，就算没有开放也没关系；
- 在浏览器中右击，点击“检查”；
- 点击“网络”(也有可能是“network”)；
- 刷新(快捷键ctrl+R)；
- 找到“name”(也有可能叫“名称”...)在其中找到`stdElectCourse.action`；
- 展开“header”，往下滑可以找到`cookies`，比如我现在的`cookies`:

![image-20250119194016936](E:\Desktop\SUFEr2024Autumn\很“刑”的自动抢课\assets\image-20250119194016936.png)

```txt
semester.id=3588; JSESSIONID=16D79987DD9E2887007C106BC2EA2DB4; _ga=GA1.3.1147437181.1720097006; _ga_R1FN4KJKJH=GS1.1.1726111562.5.0.1726111562.0.0.0; sensorsdata2015jssdkcross=%7B%22distinct_id%22%3A%22193a90149b51497-008451c05e64b6e-26011851-1600000-193a90149b62447%22%2C%22first_id%22%3A%22%22%2C%22props%22%3A%7B%7D%2C%22identities%22%3A%22eyIkaWRlbnRpdHlfY29va2llX2lkIjoiMTkzYTkwMTQ5YjUxNDk3LTAwODQ1MWMwNWU2NGI2ZS0yNjAxMTg1MS0xNjAwMDAwLTE5M2E5MDE0OWI2MjQ0NyJ9%22%2C%22history_login_id%22%3A%7B%22name%22%3A%22%22%2C%22value%22%3A%22%22%7D%2C%22%24device_id%22%3A%22193a90149b51497-008451c05e64b6e-26011851-1600000-193a90149b62447%22%7D; SF_cookie_75=40216030
```
- 现在的cookies非常丑，我们需要转换成`python`兼容的字典形式，你可以运行如下程序`trans.py`(也可以找大模型对话，要求它转换格式)：
```python
import re

cookies_txt = input()
cookies_dict = dict(re.findall(r'([^=;\s]+)=([^;]+)', cookies_txt))

print(cookies_dict)
```
程序的输出就是我们需要的`cookies`，你可以将原来`main.py`中的`cookies`替换为`trans.py`运行的结果；

#### Step5：

获取了`stdElectCourse.action`其实就获取到了`url`。

**不同的课程有自己的“课程代码”，也有自己的“选课代码”**，这需要我们进行区分；

比如“离散数学”课程的“课程代码”是：$101389$，但是它的选课代码是：$379607$。

怎么得到选课代码呢？

- 进入“全校教学计划”；
- 找到想抢的课程；
- 点击蓝色的“课程名称”；

![image-20250119194430687](E:\Desktop\SUFEr2024Autumn\很“刑”的自动抢课\assets\image-20250119194430687.png)

- 网上看，`url`中告诉了你`stdElectCourse.action`：

![image-20250119194551775](E:\Desktop\SUFEr2024Autumn\很“刑”的自动抢课\assets\image-20250119194551775.png)

- 接下来修改`main.py`中的`url`你只要把`url`中的`"这里要填electLessonIds"`换成刚刚查到的`electLessonIds`就行，比如我要抢“离散数学”我就改成：

```txt
url = "https://eams.sufe.edu.cn/eams/stdElectCourse!batchOperator.action?profileId=10084&electLessonIds=379607&withdrawLessonIds=&v=1736410587640&_=1736410587642"
```



#### Step6：

大功告成！你只需要在抢课前1分钟左右运行程序就行，程序不断向服务器发送抢课命令。服务器一旦开放，就能抢到课。

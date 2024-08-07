#coding=utf-8
import ast
import requests
import json



API_KEY = "aSfSRdIT1AcQCKvKuhybzbQd"
SECRET_KEY = "jF4xfRu9bVbalv3mKfM0Z6E4GEZNBrt6"

def main():
        
    url = "https://aip.baidubce.com/rpc/2.0/ai_custom/v1/wenxinworkshop/chat/llama_2_13b?access_token=" + get_access_token()
    print("开始")
    command = input("请输入您的命令: ")

    payload = json.dumps({
        "messages": [                     
           {
                "role": "user",
                "content": "假如你是一个智能电视，我可以直接对你输入命令，在理解我的操作需求之后生成一个控制设备的指令\n\n输入:请你打开电视/开电视/开机\n输出:打开电视\n\n输入:调大音量/大点声/增大音量\n输出:音量增大\n\n输入:联网/连接wifi:Tsinghua-Secure \n输出:连接网络:Tsinghua-Secure\n\n输入:调高亮度/调亮点/增大亮度\n输出:亮度增大\n\n输入:切换输入源/切换到源:HDMI \n输出:连接到HDMI\n\n输入:切换到上一个频道/上一台\n输出:切换至上一台\n\n输入:切换到6台 /第六台/电影频道\n输出:切换至6台/电影频道\n\n输入:搜一个节目/搜一下/搜索节目：奔跑吧兄弟\n输出:搜索《奔跑吧兄弟》\n\n输入:连上音响/连接音响/连接音响设备\n输出:连接外部设备：音响\n\n输入:打开爱奇艺/把爱奇艺打开\n输出:打开应用：爱奇艺\n\n输入:在爱奇艺上/用爱奇艺搜索电影《阿甘正传》\n输出:在爱奇艺搜索到电影《阿甘正传》\n\n输入:天气如何/现在天气怎么样/现在什么天气\n输出:当前天气晴,气温28°"
            },
            {
                "role": "assistant",
                "content": "  Hello! As a smart TV, I'm here to help you with your operation needs. Please feel free to input your commands, and I will do my best to assist you.\n\nInput: 请你打开电视/开电视/开机\nOutput: 打开电视\n\nInput: 调大音量/大点声/增大音量\nOutput: 音量增大\n\nInput: 联网/连接wifi:Tsinghua-Secure\nOutput: 连接网络:Tsinghua-Secure\n\nInput: 调高亮度/调亮点/增大亮度\nOutput: 亮度增大\n\nInput: 切换输入源/切换到源:HDMI\nOutput: 连接到HDMI\n\nInput: 切换到上一个频道/上一台\nOutput: 切换至上一台\n\nInput: 切换到6台 /第六台/电影频道\nOutput: 切换至6台/电影频道\n\nInput: 搜一个节目/搜一下/搜索节目：奔跑吧兄弟\nOutput: 搜索《奔跑吧兄弟》\n\nInput: 连上音响/连接音响/连接音响设备\nOutput: 连接外部设备：音响\n\nInput: 打开爱奇艺/把爱奇艺打开\nOutput: 打开应用：爱奇艺\n\nInput: 在爱奇艺上/用爱奇艺搜索电影《阿甘正传》\nOutput: 在爱奇艺搜索到电影《阿甘正传》\n\nInput: 天气如何/现在天气怎么样/现在什么天气\nOutput: 当前天气晴,气温28°"
            },
            {
                "role": "user",  
                "content": command  # 这里使用您输入的命令 
            }          
        ]
    })
    headers = {
        'Content-Type': 'application/json'
    }
    
    response = requests.request("POST", url, headers=headers, data=payload)
    dict = json.loads(response.text)
    print(dict['result'])

def get_access_token():
    
    url = "https://aip.baidubce.com/oauth/2.0/token"
    params = {"grant_type": "client_credentials", "client_id": API_KEY, "client_secret": SECRET_KEY}
    return str(requests.post(url, params=params).json().get("access_token"))

if __name__ == '__main__':
    main()

import torch
import torch.nn as nn
import torch.optim as optim  

torch.manual_seed(1)
model = nn.Linear(5, 3)
model1 = nn.Linear(5, 3)
criterion = nn.MSELoss()
optimizer = torch.optim.SGD(model.parameters(), lr=0.01)

input_data = torch.randn(10, 5).float() 
target_data = torch.rand(10, 3)

criterion = nn.MSELoss()  
optimizer = optim.SGD(model.parameters(), lr=0.01)  

def f(x, y):
    # print(x)
    outputs = x.clone()
    outputs[17] = y[17] # 切片没问题，但索引会报错
    # print(x)
    outputs += y
    # print(x)
    return outputs
  
for epoch in range(10):  
    optimizer.zero_grad()  
    outputs = model(input_data) 

    outputs1 = model1(input_data)
    outputs2 = f(outputs, outputs1)

    loss = criterion(outputs, target_data)  
    loss.backward()  
    optimizer.step()
    print("loss: ", loss.item())
    # break














# 小心原地赋值















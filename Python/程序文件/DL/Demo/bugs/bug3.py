import torch
import torch.nn as nn
import torch.optim as optim  

model = nn.Linear(5, 1)
criterion = nn.MSELoss()
optimizer = torch.optim.SGD(model.parameters(), lr=0.01)

input_data = torch.randn(10, 5).float() 
target_data = torch.tensor([0, 1, 2, 0, 1, 2, 0, 1, 2, 0])

criterion = nn.MSELoss()  
optimizer = optim.SGD(model.parameters(), lr=0.01)  
  
for epoch in range(10):  
    optimizer.zero_grad()  
    outputs = model(input_data)  
    loss = criterion(outputs, target_data)  
    loss.backward()  
    optimizer.step()
    print("loss: ", loss.item()) 
























# 数据类型不匹配
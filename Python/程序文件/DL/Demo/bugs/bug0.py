import torch  
import torch.nn as nn  
import torch.optim as optim  
  
model = nn.Linear(in_features=10, out_features=5)  
  
input_data = torch.randn(3, 15) 
target_data = torch.randn(3, 5)  
  
criterion = nn.MSELoss()  
optimizer = optim.SGD(model.parameters(), lr=0.01)  
  
for epoch in range(10):  
    optimizer.zero_grad()  
    outputs = model(input_data)
    loss = criterion(outputs, target_data)  
    loss.backward()  
    optimizer.step()
    print("loss: ", loss.item())




























# 数据维度不匹配
import torch  
import torch.nn as nn  
import torch.optim as optim  
  
device = torch.device("cuda")  
  
model = nn.Linear(in_features=10, out_features=5).to(device)  
  
input_data = torch.randn(3, 10)  
target_data = torch.randn(3, 5)  
  
input_data, target_data = input_data.to(device), target_data.to(device)  
  
criterion = nn.MSELoss()  
optimizer = optim.SGD(model.parameters(), lr=0.01)  
  
for epoch in range(10):  
    optimizer.zero_grad()  
    outputs = model(input_data)  
    loss = criterion(outputs, target_data)  
    loss.backward()  
    # optimizer.step()
    print("loss: ", loss.item())























# 未更新梯度
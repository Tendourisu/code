import torch  
import torch.nn as nn  
import torch.optim as optim  
  

class MyModel(nn.Module):
    def __init__(self):
        super(MyModel, self).__init__()
        self.conv = nn.Conv2d(3, 10, 3, 1, 1)
        self.fc1 = nn.Linear(10 * 4 * 4, 32)
        self.fc2 = nn.Linear(32, 1)

    def forward(self, x):
        # x: [B, C, H, W]
        x0 = self.conv(x) # [B, 10, H, W]
        # x0 = x0.view(x0.size(0), -1) # [B, 10 * H * W]
        x1 = self.fc1(x0)
        x2 = self.fc2(x1)
        return x2
    

model = MyModel(a=1)
  
input_data = torch.randn(10, 3, 4, 4) 
target_data = torch.randn(10, 5)  
  
criterion = nn.MSELoss()  
optimizer = optim.SGD(model.parameters(), lr=0.01)  
  
for epoch in range(10):  
    optimizer.zero_grad()  
    outputs = model(input_data)
    loss = criterion(outputs, target_data)  
    loss.backward()  
    optimizer.step()
    print("loss: ", loss.item())





























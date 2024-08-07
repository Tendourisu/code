import rclpy
from rclpy.node import Node
from protocol.msg import MotionServoCmd

class BackwardController(Node):
    def __init__(self, name):
        super().__init__(name)
        self.speed_x, self.speed_y, self.speed_z = 0.0, 0.0, 0.0
        self.dog_name = "cyberdog"
        self.pub = self.create_publisher(MotionServoCmd, f"/{self.dog_name}/motion_servo_cmd", 10)
        self.timer = self.create_timer(0.1, self.timer_callback)

    def timer_callback(self):
        msg = MotionServoCmd()
        msg.motion_id = 303
        msg.cmd_type = 1
        msg.value = 2
        msg.vel_des = [self.speed_x, self.speed_y, self.speed_z]
        msg.step_height = [0.05, 0.05]
        self.pub.publish(msg)

def main(args = None):
    rclpy.init(args = args)
    node = BackwardController("move_the_dog")
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
###################################################################################
import rclpy
from rclpy.node import Node
from protocol.msg import MotionServoCmd

class ForwardController(Node):
    def __init__(self, name):
        super().__init__(name)
        self.speed_x, self.speed_y, self.speed_z = 0.1, 0.0, 0.0
        self.dog_name = "cyberdog"
        self.pub = self.create_publisher(MotionServoCmd, f"/{self.dog_name}/motion_servo_cmd", 10)
        self.timer = self.create_timer(0.1, self.timer_callback)

    def timer_callback(self):
        msg = MotionServoCmd()
        msg.motion_id = 303
        msg.cmd_type = 1
        msg.value = 2
        msg.vel_des = [self.speed_x, self.speed_y, self.speed_z]
        msg.step_height = [0.05, 0.05]
        self.pub.publish(msg)

def main(args = None):
    rclpy.init(args = args)
    node = ForwardController("move_the_dog")
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()
###################################################################################
import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Range
from geometry_msgs.msg import Twist
import math

class ObstacleAvoidanceNode(Node):

    def __init__(self):
        super().__init__('obstacle_avoidance_node')
        self.cmd_vel_publisher = self.create_publisher(Twist, '/cmd_vel', 10)
        self.ultrasonic_subscriber = self.create_subscriber(Range, '/ultrasonic', self.callback)

    def callback(self, msg):
        self.ultrasonic = msg.range

    def forward(self):
        # 假设这个函数已经实现，使机器人向前移动
        cmd = Twist()
        cmd.linear.x = 0.1  # 向前移动
        self.cmd_vel_publisher.publish(cmd)

    def rotation(self):
        # 假设这个函数已经实现，使机器人逆时针旋转
        cmd = Twist()
        cmd.angular.z = -1.0  # 逆时针旋转
        self.cmd_vel_publisher.publish(cmd)

def main(args=None):
    rclpy.init(args=args)
    obstacle_avoidance_node = ObstacleAvoidanceNode()
    
    while rclpy.ok():
        rclpy.spin_once(obstacle_avoidance_node)
        distance = obstacle_avoidance_node.ultrasonic
        
        if distance < 0.5:
            obstacle_avoidance_node.rotation()
        elif distance > 1.0:
            obstacle_avoidance_node.forward()

    obstacle_avoidance_node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()

###################################################################################
import rclpy
from rclpy.node import Node
from protocol.msg import MotionServoCmd
import math

class RotateController(Node):
    def __init__(self, name):
        super().__init__(name)
        self.speed_x, self.speed_y, self.speed_z = 0.0, 0.0, 0.0  # 初始速度设为0
        self.dog_name = "cyberdog"
        self.pub = self.create_publisher(MotionServoCmd, f"/{self.dog_name}/motion_servo_cmd", 10)
        self.timer = self.create_timer(0.1, self.timer_callback)
        self.time_counter = 0.0  # 时间计数器

    def timer_callback(self):
        angle = 90  # 旋转角度，这里假设是90度
        angular_speed = 0.5  # 设置旋转的角速度，单位是弧度/秒
        time_to_rotate = abs(angle) / angular_speed  # 计算旋转需要的时间
        self.speed_z = math.copysign(angular_speed, angle)  # 根据角度确定旋转方向和速度

        msg = MotionServoCmd()
        msg.motion_id = 303
        msg.cmd_type = 1
        msg.value = time_to_rotate  # 将旋转时间设置为value字段
        msg.vel_des = [self.speed_x, self.speed_y, self.speed_z]
        msg.step_height = [0.05, 0.05]
        self.pub.publish(msg)

        self.time_counter += 0.1  # 计时器每次加0.1秒
        if self.time_counter >= time_to_rotate:  # 判断是否达到旋转时间
            self.speed_z = 0.0  # 停止旋转
            self.pub.publish(msg)  # 发布停止旋转的消息
            self.get_logger().info("Rotation completed.")
            self.timer.cancel()  # 停止定时器

def main(args = None):
    rclpy.init(args = args)
    node = RotateController("move_the_dog")
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()
###################################################################################
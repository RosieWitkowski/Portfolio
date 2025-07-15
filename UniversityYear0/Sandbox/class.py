class Car:
	def __init__(self, max_speed):
		self.max_speed = max_speed

	def start_engine(self):
		return f"VROOOMMMM!"

	def __str__(self):
		return f"{self.max_speed} is max speed."

Toyota = Car(180)
Mini = Car(157)
print(Mini)
print(Toyota.start_engine())

import numpy
from concrete_swarm import ConcreteSwarm

if __name__ == "__main__":
  iterCount = 300  # Кол-во итераций

  dimension = 1    # Кол-во измерений
  swarmsize = 30   # Кол-во частиц в рое

  minvalue = -500  # Глобальное минимальное значение
  maxvalue = 500   # Глобальное максимальное значение

  # Списки минимальных и максимальных значений по всем измерениям.
  minvalues = numpy.array([minvalue] * dimension)
  maxvalues = numpy.array([maxvalue] * dimension)

  # Коэффициенты, влияющие на скорость частиц
  currentVelocityRatio = 0.1
  localVelocityRatio = 1.0
  globalVelocityRatio = 5.0

  # Конкретный рой частиц
  swarm = ConcreteSwarm(swarmsize, minvalues, maxvalues, currentVelocityRatio,
      localVelocityRatio, globalVelocityRatio)

  # Алгоритм
  for n in range (iterCount):
    position = swarm.getSwarm()[0].getCurrentPosition()
    velocity = swarm.getSwarm()[0].getCurrentVelocity()

    print("Position: ", position)
    print("Velocity: ", velocity)
    print("\n")

    swarm.nextIteration()

print("Best position: ", swarm.globalBestPosition)
print("Best function value: ", swarm.globalBestFinalFunc)
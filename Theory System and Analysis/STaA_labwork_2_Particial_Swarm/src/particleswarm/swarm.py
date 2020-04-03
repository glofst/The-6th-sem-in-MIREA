import numpy
from abc import ABCMeta
from particleswarm.particle import Particle

class Swarm(object):
  """
  Базовый класс для роя частиц. Его надо переопределять для конкретной целевой функции
  """
  __metaclass__ = ABCMeta

  def __init__(self,
  swarmsize, 
  minvalues, 
  maxvalues, 
  currentVelocityRatio,
  localVelocityRatio, 
  globalVelocityRatio):
    """
    swarmsize - размер роя (количество частиц)
    minvalues - список, задающий минимальные значения для каждой координаты частицы
    maxvalues - список, задающий максимальные значения для каждой координаты частицы
    currentVelocityRatio - общий масштабирующий коэффициент для скорости
    localVelocityRatio - коэффициент, задающий влияние лучшей точки, 
    найденной частицей на будущую скорость
    globalVelocityRatio - коэффициент, задающий влияние лучшей точки, найденной всеми частицами на будущую скорость
    """
    self.__swarmsize = swarmsize

    self.dimension = len(minvalues)

    assert len(minvalues) == len(maxvalues)
    assert (localVelocityRatio + globalVelocityRatio) > 4

    self.minvalues = numpy.array(minvalues[:])
    self.maxvalues = numpy.array(maxvalues[:])

    self.currentVelocityRatio = currentVelocityRatio
    self.localVelocityRatio = localVelocityRatio
    self.globalVelocityRatio = globalVelocityRatio

    self.globalBestFinalFunc = None
    self.globalBestPosition = None

    self.__swarm = self.__createSwarm()

  def __createSwarm(self):
    """
    Создать рой из частиц со случайными координатами и скоростями
    """
    return [Particle(self) for _ in range (self.__swarmsize)]
  
  def getSwarm(self):
    return self.__swarm

  def nextIteration(self):
    """
    Выполнить следующую итерацию алгоритма
    """
    for particle in self.__swarm:
      particle.nextIteration(self)

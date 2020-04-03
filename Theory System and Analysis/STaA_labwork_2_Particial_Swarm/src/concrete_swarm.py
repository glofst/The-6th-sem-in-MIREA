import numpy
from particleswarm.swarm import Swarm

class ConcreteSwarm(Swarm):
  """
  Класс, представляющий из себя конкретную реализацию роя.
  В данном варианте взята функция Швефеля из методички.
  """

  def __init__(self, swarmsize, minvalues, maxvalues, currentVelocityRatio,
      localVelocityRatio, globalVelocityRatio):
    Swarm.__init__(self, swarmsize, minvalues, maxvalues, currentVelocityRatio,
        localVelocityRatio, 
        globalVelocityRatio)

  def _finalFunc(self, position):
    penalty = self._getPenalty(position, 10000.0)
    finalfunc = sum(-position * numpy.sin(numpy.sqrt(numpy.abs(position))))

    return finalfunc + penalty

  def getFinalFunc (self, position):
    assert len(position) == len(self.minvalues)

    finalFunc = self._finalFunc(position)

    if (not hasattr(self, 'globalBestFinalFunc') or
        self.globalBestFinalFunc == None or
        finalFunc < self.globalBestFinalFunc):
      self.globalBestFinalFunc = finalFunc
      self.globalBestPosition = position[:]
    
    return finalFunc

  def _getPenalty (self, position, ratio):
    """
    Рассчитать штрафную функцию
    position - координаты, для которых рассчитывается штраф
    ratio - вес штрафа
    """
    penalty1 = sum([ratio * abs(coord - minval)
                   for coord, minval in zip(position, self.minvalues) 
                   if coord < minval])

    penalty2 = sum([ratio * abs(coord - maxval)
                   for coord, maxval in zip(position, self.maxvalues) 
                   if coord > maxval ])

    return penalty1 + penalty2

package com.comp301.a05driver;

import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;
import java.util.NoSuchElementException;

public class SnakeOrderAcrossPoolsIterator implements Iterator<Driver> {
  private List<Iterator<Driver>> iteratorsList = new ArrayList<>();
  private int iteratorIndex;
  private int totalDrivers;
  private int calledDriver;
  private Driver nextDriver;
  private boolean incrementProcess;

  public SnakeOrderAcrossPoolsIterator(List<Iterable<Driver>> driverPools) {
    if(driverPools == null) {
      throw new NullPointerException();
    }
    this.totalDrivers = 0;
    this.iteratorIndex = 0;
    this.calledDriver = 0;
    this.nextDriver = null;
    this.incrementProcess = true;
    for (int i = 0; i < driverPools.size(); i++) {
      this.iteratorsList.add(driverPools.get(i).iterator());
      int temp = 0;
      for (Driver driver : driverPools.get(i)) {
        temp++;
      }
      this.totalDrivers += temp;
    }
  }

  public void loadNextDriver() {
    if(!hasNext()) {
      return;
    }
    while(true) {
      if(incrementProcess){
        while(iteratorIndex < iteratorsList.size()) {
          if (iteratorsList.get(iteratorIndex).hasNext()) {
            nextDriver = iteratorsList.get(iteratorIndex).next();
            iteratorIndex++;
            return;
          } else {
            iteratorIndex++;
          }
        }
        if (iteratorIndex == iteratorsList.size()) {
          iteratorIndex--;
          incrementProcess = false;
        }
        continue;
      } else {
        while(iteratorIndex >= 0) {
          if (iteratorsList.get(iteratorIndex).hasNext()) {
            nextDriver = iteratorsList.get(iteratorIndex).next();
            iteratorIndex--;
            return;
          } else {
            iteratorIndex--;
          }
        }
        if (iteratorIndex < 0) {
          iteratorIndex++;
          incrementProcess = true;
        }
        continue;
      }
    }
  }

  @Override
  public boolean hasNext() {
    return !(calledDriver == totalDrivers);
  }

  @Override
  public Driver next() {
    if (this.hasNext()) {
      Driver currentDriver;
      this.loadNextDriver();
      currentDriver = this.nextDriver;
      this.nextDriver = null;
      this.calledDriver++;
      return currentDriver;
    } else {
      throw new NoSuchElementException();
    }
  }

}

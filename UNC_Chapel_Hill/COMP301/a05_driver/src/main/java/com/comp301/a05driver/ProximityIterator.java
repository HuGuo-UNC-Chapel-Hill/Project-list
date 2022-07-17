package com.comp301.a05driver;

import java.util.Iterator;
import java.util.NoSuchElementException;

public class ProximityIterator implements Iterator<Driver> {
  private Iterator<Driver> iterator;
  private Driver nextDriver;
  private Position clientPosition;
  private int proximityRange;

  public ProximityIterator(Iterable<Driver> driverPool, Position clientPosition, int proximityRange) {
    if (clientPosition == null || driverPool == null) {
      throw new IllegalArgumentException();
    }
    this.iterator = driverPool.iterator();
    this.nextDriver = null;
    this.clientPosition = clientPosition;
    this.proximityRange = proximityRange;
  }

  private void loadNextDriver(){
    int range = 0;
    while (nextDriver == null && iterator.hasNext()) {
      Driver potentialDriver = iterator.next();
      range = potentialDriver.getVehicle().getPosition().getManhattanDistanceTo(clientPosition);
      if (range <= proximityRange) {
        nextDriver = potentialDriver;
        break;
      }
    }
//    if (nextDriver == null) {
//      while (iterator.hasNext()) {
//        Driver potentialDriver = iterator.next();
//        range = potentialDriver.getVehicle().getPosition().getManhattanDistanceTo(clientPosition);
//        if (range <= proximityRange) {
//          nextDriver = potentialDriver;
//          break;
//        }
//      }
//    }
  }

  @Override
  public boolean hasNext() {
    this.loadNextDriver();
    if (nextDriver != null) {
      return true;
    }
    return false;
  }

  @Override
  public Driver next() {

    if (this.hasNext()) {
      Driver currentDriver;
      currentDriver = nextDriver;
      nextDriver = null;
      return currentDriver;
    } else {
      throw new NoSuchElementException();
    }

  }
}

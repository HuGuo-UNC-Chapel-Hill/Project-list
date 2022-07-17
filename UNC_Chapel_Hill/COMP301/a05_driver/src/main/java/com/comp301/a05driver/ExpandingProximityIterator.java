package com.comp301.a05driver;

import java.util.Iterator;
import java.util.NoSuchElementException;

public class ExpandingProximityIterator implements Iterator<Driver> {
  private Iterator<Driver> iterator;
  private Iterable<Driver> driverPool;
  private Driver nextDriver;
  private Position clientPosition;
  private int expansionStep;
  private int lowBoundary;
  private int multiplier;
  private int upBoundary;
  private int totalDriver;
  private int calledDriver;


  public ExpandingProximityIterator(Iterable<Driver> driverPool, Position clientPosition, int expansionStep) {
    if(driverPool == null || clientPosition == null) {
      throw new IllegalArgumentException();
    }
    this.driverPool = driverPool;
    this.iterator = driverPool.iterator();
    this.nextDriver = null;
    this.clientPosition = clientPosition;
    this.expansionStep = expansionStep;
    this.lowBoundary = 0;
    this.multiplier = 0;
    this.upBoundary = 1;
    this.totalDriver = 0;
    for (Driver driver : driverPool) {
      this.totalDriver++;
    }
    this.calledDriver = 0;
  }

  public void loadNextDriver(){
    if(this.calledDriver != this.totalDriver){
      while (true) {
        while (this.iterator.hasNext()) {
          int range = 0;
          Driver potentialDriver = this.iterator.next();
          range = potentialDriver.getVehicle().getPosition().getManhattanDistanceTo(this.clientPosition);
          if (this.upBoundary >= range && range > this.lowBoundary) {
            this.nextDriver = potentialDriver;
            return;
          }
        }
        this.lowBoundary = this.upBoundary;
        this.multiplier++;
        this.upBoundary = 1 + this.multiplier * this.expansionStep;
        this.iterator = this.driverPool.iterator();
      }
    }
  }

  @Override
  public boolean hasNext() {
    return !(this.calledDriver == this.totalDriver);
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


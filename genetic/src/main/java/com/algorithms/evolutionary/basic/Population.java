package com.algorithms.evolutionary.basic;

import com.sun.org.apache.bcel.internal.generic.POP;

import java.util.ArrayList;
import java.util.List;

/**
 * Created by mahidhar.ramesh on 4/21/2017.
 */
public class Population {
    private List<Individual> population;
    private double populationFitness = -1;

    public Population(int populationsize) {
        this.population = new ArrayList(populationsize);
    }

    public Population(int populationSize, int chromosomeLength) {
        this.population = new ArrayList(populationSize);
        for (int individualCount = 0; individualCount < populationSize; individualCount++) {
            Individual individual = new Individual(chromosomeLength);
            this.population.add(individualCount, individual);
        }
    }

    public List<Individual> getIndividual() {
        return this.population;
    }
}

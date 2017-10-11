package com.algorithms.evolutionary.tsp;

import com.algorithms.evolutionary.tsp.Individual;

import java.util.*;

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

    public List<Individual> getIndividuals() {
        return this.population;
    }

    public Individual getFittest(int offset) {
        Collections.sort(this.population, new Comparator<Individual>() {
            @Override
            public int compare(Individual lhs, Individual rhs)
            {
                if (lhs.getFitness() > rhs.getFitness()) {
                    return -1;
                } else if ((lhs.getFitness() < rhs.getFitness())) {
                    return 1;
                }
                return 0;
            }
        });
        return this.population.get(offset);
    }

    public void setPopulationFitness(double fitness) {
        this.populationFitness = fitness;
    }

    public double getPopulationFitness() {
        return this.populationFitness;
    }

    public int size() {
        return this.population.size();
    }

    public void addIndividual(int offset, Individual individual) {
        this.population.add(offset, individual);
    }

    public void setIndividual(int offset, Individual individual) {
        this.population.set(offset, individual);
    }

    public Individual getIndividual(int offset) {
        return this.population.get(offset);
    }

    public void shuffle() {
        Random rnd = new Random();
        for (int i = this.population.size() - 1; i > 0; i--) {
            int index = rnd.nextInt(i + 1);
            Individual a = this.population.get(index);
            this.population.set(index, this.population.get(i));
            this.population.set(i, a);
        }
    }
}

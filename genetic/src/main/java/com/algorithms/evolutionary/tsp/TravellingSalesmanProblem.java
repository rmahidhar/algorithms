package com.algorithms.evolutionary.tsp;

import java.util.ArrayList;
import java.util.List;

/**
 * Created by mahidhar.ramesh on 4/21/2017.
 */
public class TravellingSalesmanProblem {
    public static int maxGenerations = 3000;
    public static void main(String[] args) {
        int numCities = 100;
        List<City> cities = new ArrayList(numCities);

        for (int index = 0; index < numCities; index++) {
            int xPos = (int) (100 * Math.random());
            int yPos = (int) (100 * Math.random());
            cities.add(index, new City(xPos, yPos));
        }

        // Create GA object
        GeneticAlgorithm ga = new GeneticAlgorithm(100, 0.001, 0.9, 2, 5);

        // Initialize population
        Population population = ga.initPopulation(cities.size());

        ga.evalPopulation(population, cities);
        int generation = 1;
         while (ga.isTerminationConditionMet(population) == false) {
             // Print the fittest individual from population
             Route route = new Route(population.getFittest(0), cities);
             System.out.println("G" + generation + " Best distance: " + route.getDistance());

             // Apply crossover
             population = ga.crossoverPopulation(population);

             // Apply mutation
             population = ga.mutatePopulation(population);

             // Evaluate population
             ga.evalPopulation(population, cities);

             // Increment the current generation
             generation++;
         }

        System.out.println("Stopped after " + maxGenerations + " generations.");
        Route route = new Route(population.getFittest(0), cities);
        System.out.println("Best distance: " + route.getDistance());    }
}

package com.algorithms.evolutionary.basic;

/**
 * Created by mahidhar.ramesh on 4/21/2017.
 */
public class AllOnesGA {
    public static void main(String[] args) {
        // Create GA object
        GeneticAlgorithm ga = new GeneticAlgorithm(100, 0.001, 0.95, 2);

        // Initialize population
        Population population = ga.initPopulation(50);

        ga.evalPopulation(population);
        int generation = 1;
         while (ga.isTerminationConditionMet(population) == false) {
             // Print the fittest individual from population
             System.out.println("Best solution: " + population.getFittest(0).toString());

             // Apply crossover
             population = ga.crossoverPopulation(population);

             // Apply mutation
             population = ga.mutatePopulation(population);

             // Evaluate population
             ga.evalPopulation(population);

             // Increment the current generation
             generation++;
         }

         System.out.println("Found solution in " + generation + " generations");
         System.out.println("Best solution: " + population.getFittest(0).toString());
    }
}

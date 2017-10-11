package com.algorithms.evolutionary.tsp;

import java.util.List;

/**
 * Created by mahidhar.ramesh on 4/21/2017.
 */
public class GeneticAlgorithm {
    private int populationSize;
    private double mutationRate;
    private double crossoverRate;
    private int elitismCount;
    protected int tournamentSize;

    public GeneticAlgorithm(int populationSize, double mutationRate,
                            double crossoverRate, int elitismCount,
                            int tournamentSize) {
        this.populationSize = populationSize;
        this.mutationRate = mutationRate;
        this.crossoverRate = crossoverRate;
        this.elitismCount = elitismCount;
        this.tournamentSize = tournamentSize;
    }

    public Population initPopulation(int chromosomeLength) {
        Population population = new Population(this.populationSize, chromosomeLength);
        return population;
    }

    // In the evaluation stage, each individual in the population has their fitness value calculated
    // and store for future use.
    public void evalPopulation(Population population, List<City> cities) {
        double populationFitness = population.getIndividuals().stream().mapToDouble(individual -> individual.calcFitness(cities)).sum();
        population.setPopulationFitness(populationFitness);
    }

    public boolean isTerminationConditionMet(Population population) {
        return population.getIndividuals().stream().filter(individual -> individual.getFitness() == 1).count()
                >= 1;
    }

    public Individual selectParent(Population population) {
        // Spin roulette wheel
        double populationFitness = population.getPopulationFitness();
        double rouletteWheelPosition = Math.random() * populationFitness;

        // Find parent
        double spinWheel = 0;
        for (Individual individual : population.getIndividuals()) {
            spinWheel += individual.getFitness();
            if (spinWheel >= rouletteWheelPosition) {
                return individual;
            }
        }
        return population.getIndividuals().get(population.size() - 1);
    }

    public Population crossoverPopulation(Population population) {
        // Ordered cross over

        // Create new population
        Population newPopulation = new Population(population.size());

        // Loop over current population by fitness
        for (int index = 0; index < population.size(); index++) {
            Individual parent1 = population.getFittest(index);

            // Apply crossover to this individual?
            if (this.crossoverRate > Math.random() && index > this.elitismCount) {
                // Initialize offspring
                Individual offspring = new Individual(parent1.getChromosomeLength(), -1);

                // Find second parent
                Individual parent2 = selectParent(population);

                // Get parent1 chromosomes
                int pos1 = (int) (Math.random() * parent1.getChromosomeLength());
                int pos2 = (int) (Math.random() * parent1.getChromosomeLength());

                final int si = Math.min(pos1, pos2);
                final int ei = Math.min(pos1, pos2);

                for (int geneIndex = si; geneIndex < ei; geneIndex++) {
                    offspring.setGene(geneIndex, parent1.getGene(geneIndex));
                }

                // Get parent2 chromosomes
                int chromosomeLength = offspring.getChromosomeLength();
                for (int i = 0; i < chromosomeLength; i++) {
                    if (i < si || i >= ei) {
                        int geneIndex = (ei + i) % chromosomeLength;
                        if (!offspring.containsGene(parent2.getGene(geneIndex))) {
                            offspring.setGene(i, parent2.getGene(geneIndex));
                        }
                    }
                }

                // Add offspring to new population
                newPopulation.addIndividual(index, offspring);
            } else {
                // Add individual to new population without applying crossover
                newPopulation.addIndividual(index, parent1);
            }
        }
        return newPopulation;
    }

    public Population mutatePopulation(Population population) {
        // Create new population
        Population newPopulation = new Population(population.size());

        // Loop over current population by fitness
        for (int index = 0; index < population.size(); index++) {
            Individual individual = population.getFittest(index);

            if (index >= this.elitismCount) {
                for (int geneIndex = 0; geneIndex < individual.getChromosomeLength(); geneIndex++) {
                    if (this.mutationRate > Math.random()) {
                        int pos = (int) (Math.random() * individual.getChromosomeLength());
                        int gene1 = individual.getGene(pos);
                        int gene2 = individual.getGene(geneIndex);
                        individual.setGene(geneIndex, gene1);
                        individual.setGene(pos, gene2);
                    }
                }
            }
            newPopulation.addIndividual(index, individual);
        }
        return newPopulation;
    }
}

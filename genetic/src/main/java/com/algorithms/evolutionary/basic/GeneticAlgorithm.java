package com.algorithms.evolutionary.basic;

/**
 * Created by mahidhar.ramesh on 4/21/2017.
 */
public class GeneticAlgorithm {
    private int populationSize;
    private double mutationRate;
    private double crossoverRate;
    private int elitismCount;

    public GeneticAlgorithm(int populationSize, double mutationRate, double crossoverRate, int elitismCount) {
        this.populationSize = populationSize;
        this.mutationRate = mutationRate;
        this.crossoverRate = crossoverRate;
        this.elitismCount = elitismCount;
    }

    public Population initPopulation(int chromosomeLength) {
        Population population = new Population(this.populationSize, chromosomeLength);
        return population;
    }

    // In the evaluation stage, each individual in the population has their fitness value calculated
    // and store for future use.
    public void evalPopulation(Population population) {
        double populationFitness = population.getIndividuals().stream().mapToDouble(Individual::calcFitness).sum();
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
        // Create new population
        Population newPopulation = new Population(population.size());

        // Loop over current population by fitness
        for (int index = 0; index < population.size(); index++) {
            Individual parent1 = population.getFittest(index);

            // Apply crossover to this individual?
            if (this.crossoverRate > Math.random() && index > this.elitismCount) {
                // Initialize offspring
                Individual offspring = new Individual(parent1.getChromosomeLength());

                // Find second parent
                Individual parent2 = selectParent(population);

                // Loop over genome
                for (int geneIndex = 0; geneIndex < parent1.getChromosomeLength(); geneIndex++) {
                    // Use half of parent1's genes and half of parent2's genes
                    if (0.5 > Math.random()) {
                        offspring.setGene(geneIndex, parent1.getGene(geneIndex));
                    } else {
                        offspring.setGene(geneIndex, parent2.getGene(geneIndex));
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
                // Loop over genome
                for (int geneIndex = 0; geneIndex < individual.getChromosomeLength(); geneIndex++) {
                    if (this.mutationRate > Math.random()) {
                        // Get new gene
                        int newGene = 1;
                        if (individual.getGene(geneIndex) == 1) {
                            newGene = 0;
                        }
                        // Mutate gene
                        individual.setGene(geneIndex, newGene);
                    }
                }
            }
            newPopulation.addIndividual(index, individual);
        }
        return newPopulation;
    }
}

package com.algorithms.evolutionary.basic;

import java.util.ArrayList;
import java.util.List;
import java.util.stream.Collectors;

/**
 * Created by mahidhar.ramesh on 4/21/2017.
 */
public class Individual {
    private List<Integer> chromosome;
    private double fitness = -1;

    public Individual(List<Integer> chromosome) {
        this.chromosome = chromosome;
    }

    public Individual(int chromosomeLength) {
        this.chromosome = new ArrayList(chromosomeLength);
        for (int gene = 0; gene < chromosomeLength; gene++) {
            if (0.5 < Math.random()) {
                this.addGene(gene, 1);
            } else {
                this.addGene(gene, 0);
            }
        }
    }

    public List<Integer> getChromosome() {
        return this.chromosome;
    }

    public int getChromosomeLength() {
        return this.chromosome.size();
    }

    public void addGene(int offset, int gene) {
        this.chromosome.add(offset, gene);
    }

    public void setGene(int offset, int gene) {
        this.chromosome.set(offset, gene);
    }

    public int getGene(int offset) {
        return this.chromosome.get(offset);
    }

    public void setFitness(double fitness) {
        this.fitness = fitness;
    }

    public double getFitness() {
        return this.fitness;
    }

    public double calcFitness() {
        // Track number of correct genes
        long correctGenes = this.chromosome.stream().filter(gene -> gene == 1).count();
        this.fitness = (double) correctGenes / getChromosomeLength();
        return fitness;
    }

    public String toString() {
        return this.chromosome.stream().map(i -> i.toString()).collect(Collectors.joining(""));
    }

}

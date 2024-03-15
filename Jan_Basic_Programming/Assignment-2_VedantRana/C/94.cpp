#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>
#include <random>

class SkipGramModel
{
public:
    SkipGramModel(int vocabSize, int embedSize, double learningRate)
        : vocabSize(vocabSize), embedSize(embedSize), learningRate(learningRate)
    {

        wordVectors.resize(vocabSize, std::vector<double>(embedSize, 0.0));

        weights.resize(embedSize, std::vector<double>(vocabSize, 0.0));
    }

    void train(const std::vector<std::vector<int>> &sentences, int windowSize, int epochs)
    {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<double> dist(-1.0, 1.0);

        for (int i = 0; i < vocabSize; ++i)
        {
            for (int j = 0; j < embedSize; ++j)
            {
                wordVectors[i][j] = dist(gen);
            }
        }

        for (int epoch = 0; epoch < epochs; ++epoch)
        {
            for (const auto &sentence : sentences)
            {
                for (int i = 0; i < sentence.size(); ++i)
                {
                    int targetWord = sentence[i];

                    for (int j = std::max(0, i - windowSize); j <= std::min(i + windowSize, static_cast<int>(sentence.size()) - 1); ++j)
                    {
                        if (i != j)
                        {
                            int contextWord = sentence[j];

                            updateWordVectors(targetWord, contextWord);
                        }
                    }
                }
            }
        }
    }

    std::vector<double> getWordVector(int wordIndex) const
    {
        return wordVectors[wordIndex];
    }

private:
    int vocabSize;
    int embedSize;
    double learningRate;
    std::vector<std::vector<double>> wordVectors;
    std::vector<std::vector<double>> weights;

    void updateWordVectors(int targetWord, int contextWord)
    {
        std::vector<double> targetVector = wordVectors[targetWord];

        std::vector<double> scores(vocabSize, 0.0);
        for (int i = 0; i < vocabSize; ++i)
        {
            for (int j = 0; j < embedSize; ++j)
            {
                scores[i] += targetVector[j] * weights[j][i];
            }
        }

        std::vector<double> probabilities(vocabSize, 0.0);
        double sumExp = 0.0;
        for (int i = 0; i < vocabSize; ++i)
        {
            probabilities[i] = std::exp(scores[i]);
            sumExp += probabilities[i];
        }
        for (int i = 0; i < vocabSize; ++i)
        {
            probabilities[i] /= sumExp;
        }

        for (int i = 0; i < vocabSize; ++i)
        {
            double label = (i == contextWord) ? 1.0 : 0.0;
            double error = probabilities[i] - label;
            for (int j = 0; j < embedSize; ++j)
            {
                weights[j][i] -= learningRate * error * targetVector[j];
                wordVectors[targetWord][j] -= learningRate * error * weights[j][i];
            }
        }
    }
};

int main()
{

    std::vector<std::vector<int>> sentences = {{0, 1, 2, 3}, {1, 2, 4, 5}};
    int vocabSize = 6;
    int embedSize = 3;
    double learningRate = 0.01;
    int windowSize = 1;
    int epochs = 100;

    SkipGramModel skipGramModel(vocabSize, embedSize, learningRate);
    skipGramModel.train(sentences, windowSize, epochs);

    for (int i = 0; i < vocabSize; ++i)
    {
        std::cout << "Word " << i << " vector: ";
        std::vector<double> wordVector = skipGramModel.getWordVector(i);
        for (double value : wordVector)
        {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}

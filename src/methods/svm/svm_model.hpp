#ifndef SVM_MODEL_HPP_
#define SVM_MODEL_HPP_
#include "svm_node.hpp"
#include "svm_params.hpp"



struct svm_model {
    /**
     * 结构体svm_model用于保存训练后的训练模型, 在predict中要用到, 原来的训练参数也必须保留。
    */
    struct svm_params parms;    // parameters in training step
    int n_classes;              //the number of classes
    int n_sv;                   //the number of support vectors
    struct svm_node **sv;       //support vector, 保存支持向量的指针，至于支持向量的内容，如果是从文件中读取，内容会
                                // 额外保留；如果是直接训练得来，则保留在原来的训练集中。如果训练完成后需要预报，原来的
                                // 训练集内存不可以释放

    double **W;                 //the weights, coefficients for SVs in decision functions
    double *b;                  //the biases, constants in decision functions

    double *prob_A;             //pariwise probability information
    double *prob_B;
    int sv_index;               //sv_indices[0,...,nSV-1] are values in [1,...,num_traning_data] to indicate SVs in the training set

    // for classification only
    int *c_lable;               //label for each class label[i]
    int *n_c_sv;                //number of suport vector for each class n_s_v[i], nSV[0] + nSV[1] + ... + nSV[k-1] = l

    int free_sv;


};

#endif /*SVM_MODEL_HPP_*/

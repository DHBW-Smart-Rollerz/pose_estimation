//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// _coder_peInterface_info.cpp
//
// Code generation for function 'peInterface'
//

// Include files
#include "_coder_peInterface_info.h"
#include "emlrt.h"
#include "tmwtypes.h"

// Function Declarations
static const mxArray *emlrtMexFcnResolvedFunctionsInfo();

// Function Definitions
static const mxArray *emlrtMexFcnResolvedFunctionsInfo()
{
  const mxArray *nameCaptureInfo;
  const char_T *data[7]{
      "789ced58cd6eda40105eaa94a687b65cdaa7a8e214aa543d260412d4429008515b5a85c5"
      "9e8013ff75bd2072e833f47522f5d2430f7d0c1ea53866c15eb13292"
      "1d17ccce65187d9ef9bc63fc79342857abe71042cf916fcda2ef9fcde2c2cc3f4261e3f1"
      "dccc3fe562668fd14e288fe13f675eb52d0a63ea071636619ea9d9a6",
      "6e618b9edf3a8008b8b63102ed1eb9d20d38d74d680583861799d500340f3cc8fb5d1e80"
      "7ad31a9a880cdcc51d1ac160de8fdf82f3eeacd88faf827e1438bc53"
      "f9a6b45d20ae6262a2da043b8e720c23306cc7048b2af5c3f38f87474a8b0e351d2c4c7a"
      "a053a5f2a17a59331d03bc4b742043abaf946d0d88e2406dda4f7285",
      "55d83383e771629e877f7efc7918deb45da8b8543731b54980bf1b933f2fe4f711cd1ef6"
      "0c58f0ddc5e4fb24e40be39d7242cf2fd4b83d33aa6f2f563c07ef17"
      "d7efdefb5ff9fcc0f369f1bdfb73f73a4d3e66ff8b6f2ca8b7eafff0a580afc0e195d211"
      "718bfbfbe3d100de1f9c563f9f5dd46f02f7d18ce089ba0f2488d3aa",
      "df15e447f59137511f93e263f59f08f97cc421a0e92a5d1b7dfe1b931f47f033bc73f640"
      "8299631df56d5bf425eb7c71f5f39580afc0e1ed2f8d8b8393d6f175"
      "e3f47bfbba7fdbc4a5a67a921dfd9c08f257ede30f41fd02872736cff2af7728be0c47d8"
      "b2adaa6abd419b3feff2b6eaf74acebbcbfde27a39efa6c127e7dd64",
      "ea4f04f959d2eb22927a2df57af939a45ea7c327f53a99fa5d41fea6ee27a6524140ee27"
      "12fc20b28efab62dfa92753eb99f48a6fe44909fa579b784e4bc2be7"
      "dde5e790f36e3a7c72de4da6fe44909f25bd7e8ba45e4bbd5e7e0ea9d7e9f049bd4ea67e"
      "5790bfaefb895d2e5ef0f9481f688b620aeba2cf71f713bd087e863f",
      "dc7e8275d4e7d9167dc93a9fdc4f2453bf2bc85f57fd8cdaef4edf764f00d666beddfcfd"
      "2eeba86fdba22f59e793fa19affe3f8a4b2516",
      ""};
  nameCaptureInfo = nullptr;
  emlrtNameCaptureMxArrayR2016a(&data[0], 12904U, &nameCaptureInfo);
  return nameCaptureInfo;
}

mxArray *emlrtMexFcnProperties()
{
  mxArray *xEntryPoints;
  mxArray *xInputs;
  mxArray *xResult;
  const char_T *propFieldName[9]{"Version",
                                 "ResolvedFunctions",
                                 "Checksum",
                                 "EntryPoints",
                                 "CoverageInfo",
                                 "IsPolymorphic",
                                 "PropertyList",
                                 "UUID",
                                 "ClassEntryPointIsHandle"};
  const char_T *epFieldName[8]{
      "QualifiedName",    "NumberOfInputs", "NumberOfOutputs", "ConstantInputs",
      "ResolvedFilePath", "TimeStamp",      "Constructor",     "Visible"};
  xEntryPoints =
      emlrtCreateStructMatrix(1, 1, 8, (const char_T **)&epFieldName[0]);
  xInputs = emlrtCreateLogicalMatrix(1, 6);
  emlrtSetField(xEntryPoints, 0, "QualifiedName",
                emlrtMxCreateString("peInterface"));
  emlrtSetField(xEntryPoints, 0, "NumberOfInputs",
                emlrtMxCreateDoubleScalar(6.0));
  emlrtSetField(xEntryPoints, 0, "NumberOfOutputs",
                emlrtMxCreateDoubleScalar(2.0));
  emlrtSetField(xEntryPoints, 0, "ConstantInputs", xInputs);
  emlrtSetField(
      xEntryPoints, 0, "ResolvedFilePath",
      emlrtMxCreateString("/Users/marcorapp/Development/MATLAB/Studienarbeit/"
                          "EKF_Implementierung/Coder/peInterface.m"));
  emlrtSetField(xEntryPoints, 0, "TimeStamp",
                emlrtMxCreateDoubleScalar(739728.44976851856));
  emlrtSetField(xEntryPoints, 0, "Constructor",
                emlrtMxCreateLogicalScalar(false));
  emlrtSetField(xEntryPoints, 0, "Visible", emlrtMxCreateLogicalScalar(true));
  xResult =
      emlrtCreateStructMatrix(1, 1, 9, (const char_T **)&propFieldName[0]);
  emlrtSetField(xResult, 0, "Version",
                emlrtMxCreateString("24.2.0.2863752 (R2024b) Update 5"));
  emlrtSetField(xResult, 0, "ResolvedFunctions",
                (mxArray *)emlrtMexFcnResolvedFunctionsInfo());
  emlrtSetField(xResult, 0, "Checksum",
                emlrtMxCreateString("4ObMwGYhUDfFyERlqtZvjH"));
  emlrtSetField(xResult, 0, "EntryPoints", xEntryPoints);
  return xResult;
}

// End of code generation (_coder_peInterface_info.cpp)

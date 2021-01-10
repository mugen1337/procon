---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 193, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../type/ModInt.cpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/bitwise_xor_convolution\"\
    \n\n#include \"../template.cpp\"\n\n#include \"../type/ModInt.cpp\"\n\n#include\
    \ \"../Math/XorConvolution.cpp\"\n\nusing mint=ModInt<998244353>;\n\nsigned main(){\n\
    \    int n;cin>>n;\n    vector<mint> a(1<<n),b(1<<n);\n    cin>>a>>b;\n    cout<<XorConvolution(a,b)<<endl;\n\
    \    return 0;\n}"
  dependsOn: []
  isVerificationFile: true
  path: test/yosupo_Bitwise_Xor_Convolution.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo_Bitwise_Xor_Convolution.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo_Bitwise_Xor_Convolution.test.cpp
- /verify/test/yosupo_Bitwise_Xor_Convolution.test.cpp.html
title: test/yosupo_Bitwise_Xor_Convolution.test.cpp
---
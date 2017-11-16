# YesWorkflow - native executable edition

The software in this repository represents a production-quality compiled C++ implementation of YesWorkflow.  Development is in progress.  The first 1.0 beta release is expected by the end of November 2017.

General features initially will match those of the YesWorkflow research prototype
available in the [yw-prototypes](https://github.com/yesworkflow-org/yw-prototypes) repository.
Please see the [yw-prototypes README](https://github.com/yesworkflow-org/yw-prototypes/blob/master/README.md) for an introduction to YesWorkflow, references to publications, and a basic tutorial on YW.

### Usability advantages

Installation and use of the native C++ implementation of YesWorkflow is expected to be simpler compared to the Java research prototype:

Java research prototype ([yw-prototypes](https://github.com/yesworkflow-org/yw-prototypes)) | C++ implementation ([yw](https://github.com/yesworkflow-org/yw))
----------------------------------------|------------------------
Distributed as Java archive (JAR) files. | Will be distributed as native executables.
Requires installation of Java Runtime Environment (JRE) on user machine. | No Java installation will be required.
Requires full installation of Graphviz on user machine. | Core Graphviz libraries will be statically linked and included in YW executables.
User must invoke Graphviz (dot) separately to produce graphics files (SVGs, PNGs, PDFs, etc). | YW executables will output graphics files directly.
In-memory database is built for each run of YW. | Internal database will be persistent and will store multiple YW models for subsequent query and visualization.
Provenance queries and visualizations require installation of DLV, XSB, or other logic engine. | YW executables will statically link to XSB library for built-in advanced provenance query support.

### Updates to the YW annotation language

The new implementation of YesWorkflow will be backwards compatible with existing YW annotations. Planned updates and new language features include:

* **Lightweight data structure definitions.** A new `@partof` annotation will indicate that a particular input or output of a code block is part of another declared input or output on that block.  It will be straightforward to indicate that a code block accesses or updates a particular field of an input data record (or element of an array, entry in a dictionary, file in a collection, etc).  Visualizations optionally will reveal the component dataflows, the composite dataflows, or both.

* **Dataflow rate declarations.**  Optional expressions associated with `@in` and `@out` annotations will flexibly declare the cardinalities of code block inputs and outputs, i.e. the expected number of data items input or output by each port per invocation of the corresponding block.  We expect these dataflow rates to be useful both for validating YW markup and for inferring information about runtime events from artifacts left behind by runs of a script or program marked up with YW.

* **Fine-grained data dependency assertions.**  New annotations will reveal that particular outputs of a code block depend in different ways on distinct subsets of the inputs to that block.  See [Declarative Rules for Inferring Fine-Grained Data Provenance from Scientific Workflow Execution Traces](https://link.springer.com/chapter/10.1007%2F978-3-642-34222-6_7) (Bowers et al. 2012) for example uses of such assertions.

* **Deprecation of YW annotations easily confused with code documentation tags.**  The YW `@param` and `@return` annotations will continue to be optionally recognized and supported, but it will be possible to declare all ports via `@in` and `@out` annotations while maintaining the distinction between different kinds of ports.  The semantic significance of parameters and return values will be inferred from context and other annotations, e.g. data dependency assertions.

* **Flexible annotation syntax.**  Examples:  White space will be allowed in names of code and data blocks. Single `@in` and `@out` will optionally take multiple port names as arguments. The argument to the `@end` annotation will be optional.

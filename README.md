# yw

The software in this repository aims to represent a production-quality, natively compiled C++ implementation of YesWorkflow.  

General features initially will match those of the YesWorkflow research prototype
available in the [yw-prototypes](https://github.com/yesworkflow-org/yw-prototypes) repository.
Please see the [README for the research prototype](https://github.com/yesworkflow-org/yw-prototypes/blob/master/README.md) for an introduction to YesWorkflow, references to publications, and a basic tutorial.

### Advantages over research prototype

Installation and use  of the native C++ implementation of YesWorkflow is expected to be simpler 
compared to the Java research protype:

Java research prototype (yw-prototypes) | C++ implementation (yw)
----------------------------------------|------------------------
Distributed as Java archive (jar) files. | Distributed as native executables.
Requires installation of Java Runtime Environment (JRE) on user machine. | No JRE required.
Requires full installation of Graphviz on user machine. | Graphviz library statically linked and included in yw executables.
User must invoke Graphviz (dot) separately to produce graphics files (SVGs, PNGs, PDFs, etc). | YW executables output graphics files directly.
In-memory database built for each run of YW. | Internal SQLite database can be saved and can store multiple YW models for subsequent query and visualization.
Provenance queries and visualizations require installation of DLV, XSB, or other logic engine. | YW executables statically linked to XSB libraries for built-in provenance query support.

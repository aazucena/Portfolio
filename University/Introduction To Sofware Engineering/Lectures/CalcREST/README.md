[![build status](http://gitlab.cs.uleth.ca/cpsc3720/Examples/CalcREST/badges/master/build.svg)](http://gitlab.cs.uleth.ca/cpsc3720/Examples/CalcREST/commits/master)
![coverage](http://gitlab.cs.uleth.ca/cpsc3720/Examples/CalcREST/badges/master/coverage.svg?job=coverage)

# Overview #
This is an example of a software service using the REST architecture pattern.

# Implementation Details #
This implemenation uses the [restbed](https://github.com/Corvusoft/restbed) framework for implementing the REST endpoints. It also uses the [nlohmann/json](https://github.com/nlohmann/json) library for handling JSON messages.

# Example Usage #
Once you have started `calcServer` on your computer, you can click these links to see the JSON server response.

* http://localhost:1234/calc?op=add&first=1&second=1
* http://localhost:1234/calc?op=sub&first=2&second=4
* http://localhost:1234/calc?op=mul&first=12.34&second=56.78
* http://localhost:1234/calc?op=div&first=144&second=-12
* http://localhost:1234/calc?op=div&first=144&second=0 (gives an "Divison by zero" error)
* http://localhost:1234/calc?op=addition&first=1&second=0 (gives an "Invalid Operator" error) 

# Example HTML & Javascript #
The [CalcRESTClient.html](CalcRESTClient.html) file provides an example of an HTML/Javascript page that uses the REST service.

To use it:
  * Open the file in a web browser
  * Enter two numbers
  * Select the operation to use
  * Click `Call Server`
  * Note the result is returned under the button.
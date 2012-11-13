\name{trimAll}
\alias{trimAll}
\title{Trim whitespace from start and end of string}
\usage{
  trimAll(input)
}
\arguments{
  \item{input}{input character vector}
}
\value{
  character vector with leading and trailing whitespace
  removed
}
\description{
  Trim whitespace from start and end of string
}
\examples{
\dontrun{
trimAll("\\n\\nString with trailing and leading white space \\t")
}
}


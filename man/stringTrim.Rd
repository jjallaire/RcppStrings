\name{stringTrim}
\alias{stringTrim}
\title{Trim whitespace from start and end of string}
\usage{
  trim(input, side = "both")
}
\arguments{
  \item{input}{input character vector}

  \item{side}{side on which whitespace is removed (left,
  right, or both)}
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
trimString("\\n\\nString with trailing and leading white space \\t")
}
}


// ! CODE COPIED FROM TUTORIAL PART 6

import React from "react";
import { graphql } from "gatsby";
import { css } from "@emotion/core";
import { rhythm } from "../utils/typography";
import Layout from "../components/layout";

export default ({ data }) => {
    console.log(data);
    return (
        <Layout>
            <div>
                <h1
                    css={css`
            display: inline-block;
            border-bottom: 1px solid;
          `}
                >
                    Amazing Pandas Eating Things
        </h1>
                <h4>{data.allMarkdownRemark.totalCount} Posts</h4>
                {/* // - Basically at this point, we iterated through
        // - the whole markdowns existing within the scope of this web-app.
        // - With that, it process it and gets all information especially, excerpt, headings
        // - and any other such. */}
                {data.allMarkdownRemark.edges.map(({ node }) => (
                    <div key={node.id}>
                        <h3
                            css={css`
                margin-bottom: ${rhythm(1 / 4)};
              `}
                        >
                            {node.frontmatter.title}{" "}
                            <span
                                css={css`
                  color: #bbb;
                `}
                            >
                                — {node.frontmatter.date}
                            </span>
                        </h3>
                        <p>{node.excerpt}</p>
                    </div>
                ))}
            </div>
        </Layout>
    )
}

// - Any candidates of the markdown are accessible. Not only just what is the last known deep context.
// ! Means, you can access id, frontmatter and excerpt, other than frontmatter.title and frontmatter.date.

// * This query is unsorted. Deprecated #1.
// export const query = graphql`
//   query {
//     allMarkdownRemark {
//       totalCount
//       edges {
//         node {
//           id
//           frontmatter {
//             title
//             date(formatString: "DD MMMM, YYYY")
//           }
//           excerpt
//         }
//       }
//     }
//   }
// `

// @observe | This Query is now customized and sorted all markdown post in descending.
export const query = graphql`
query MyCustomQuery {
    allMarkdownRemark(sort: {fields: frontmatter___date, order: DESC}) {
      totalCount
      edges {
        node {
          id
          rawMarkdownBody
          frontmatter {
            title
            date(formatString: "DD MMMM, YYYY")
          }
          excerpt
        }
      }
    }
  }
`

// @mastery — Try creating a new page containing a blog post and
// @mastery — see what happens to the list of blog posts on the homepage!
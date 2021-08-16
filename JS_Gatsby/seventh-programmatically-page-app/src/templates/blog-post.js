// ! Since we already implemented the slugs for those markdowns to be accessed.
// # We need to create a page for it to render its contents.

import React from 'react';
import { graphql } from "gatsby";
import Layout from "../components/layout";

export default ({ data }) => {
    // ! Get Queried Data Over Passed Arguments After Querying from query variable below.
    const post = data.markdownRemark; // ! Target Literal Markdown.

    // - Now render by accessing post properties from data.markdownRemark Subtree Properties.
    // ! DangerouslySetInnerHTML Property makes NodeJS know that the source of that particular content is from another source.
    // # I can't make any comments further about this one. As I still don't understand it properly.
    // # Go further: https://zhenyong.github.io/react/tips/dangerously-set-inner-html.html
    return (
        <Layout>
            <div>
                <h1>{post.frontmatter.title}</h1>
                <div dangerouslySetInnerHTML={{ __html: post.html }} />
            </div>
        </Layout>
    )
}

export const query = graphql`
  query($slug: String!) {
    markdownRemark(fields: { slug: { eq: $slug } }) {
      html
      frontmatter {
        title
      }
    }
  }
`
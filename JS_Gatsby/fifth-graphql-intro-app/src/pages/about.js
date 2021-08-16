import React from 'react';
import { graphql } from "gatsby"; // ! Include GraphQL from the Components Layout To Adapt.
import Layout from "../components/layout";

// ! In before, we don't have a parameter here.
// ! But now, we do as we query the data. The objective was to gather
// ! The metadata declared in ../../Gatsby-config.JS

export default ({ data }) => (
    <Layout>
        <h1>About {data.site.siteMetadata.title}</h1>
        <p>
            We're the only site running on your computer dedicated to showing the best
            photos and videos of pandas eating lots of food.
    </p>
    </Layout>
)

// ! We reiterate some things that we did in the Third App.
// * Follow the instructions from the documentation tutorial or
// * please refer to that 'third' app for more information on how these files work.

// ! We now have to query in GraphQL. Notice that tree structure was the same
// ! as how we reference it inside the H1 Tag. Except it starts with data.XXXXXXX
export const query = graphql`
  query {
    site {
      siteMetadata {
        title
      }
    }
  }
`
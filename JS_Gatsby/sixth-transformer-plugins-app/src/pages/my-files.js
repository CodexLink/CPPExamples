import React from 'react';
import { graphql } from "gatsby";
import Layout from "../components/layout";

// ! I just noticed. You use {} if only there is one or more
// ! Callable Function or any other such that doesn't involve any HTML elements.
// - Then you can wrap () those HTML elements. You should add return at some point at times.
// - But if no non-HTML elements added, adding return is not required. As you're returning the
// - HTML without any explicits.
export default ({ data }) => {
  // ! A console.log would expose current files and any other such from the query.
  console.log(data);
  // ! Changed From Hello World to File Output based from Query.
  return (
    <Layout>
      <div>
        <h1>My Site's Files</h1>
        <table>
          <thead>
            <tr>
              <th>relativePath</th>
              <th>prettySize</th>
              <th>extension</th>
              <th>birthTime</th>
            </tr>
          </thead>
          <tbody>
            {/* // ! For each edges element, map them at the following: node and index.
            // ! Index was used to integrate unique key for each row.
            // - node context contains subtree such as relativePath, prettySize and other such.
            // - This code output the following for each edge elements. */}
            {data.allFile.edges.map(({ node }, index) => (
              <tr key={index}>
                <td>{node.relativePath}</td>
                <td>{node.prettySize}</td>
                <td>{node.extension}</td>
                <td>{node.birthTime}</td>
              </tr>
            ))}
          </tbody>
        </table>
      </div>
    </Layout>
  )
}

// ! This Query quries files inside of src folder. This includes subfolders as well.
export const query = graphql`
query {
    allFile {
      edges {
        node {
          relativePath
          prettySize
          extension
          birthTime(fromNow: true)
        }
      }
    }
  }
`